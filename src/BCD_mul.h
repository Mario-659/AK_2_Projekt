#ifndef BCD_MUL_H
#define BCD_MUL_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "BCD.h"
#include "BCD_add.h"

inline std::vector<unsigned char> bcd_mul(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b) {
    std::vector<unsigned char> result;
    std::vector<std::vector<unsigned char>> partial_products;

    int zero_counter = 0;
    for (int i = b.size() - 1; i >= 0; --i) {
        unsigned char digitB = b[i];
        unsigned char carry = 0;
        std::vector<unsigned char> partial_product;
        partial_product.resize(a.size(), 0);
        for (int j = a.size() - 1; j >= 0; --j) {
            unsigned char digitA = a[j];
            unsigned char product = digitA * digitB;

            __asm__(
                "add %2, %0\n\t"
                "aam\n\t"
                "mov %%ah, %1"
                : "+a"(product), "=r"(carry)
                : "r"(carry)
                : "cc"
            );

            partial_product[j] = product;
        }

        if (carry != 0) {
            partial_product.insert(partial_product.begin(), carry);
        }

        // can be impoved
        for (int i = 0; i < zero_counter; ++i) {
            partial_product.push_back(0x00);
        }
        zero_counter++;
        

        partial_products.push_back(partial_product);
    }


    result = partial_products[0];
    for (int i = 1; i < partial_products.size(); ++i) {
        result = bcd_add(partial_products[i], result);
    }

    return result;
}

inline BCD multiply_bcd(const BCD& a, const BCD& b) {
    // will break multiplication into 4 stages:
    //   1. a.digits_before_point * b.digits_before_point
    //   2. a.digits_before_point * b.digits_after_point
    //   3. a.digits_after_point * b.digits_before_point
    //   4. a.digits_after_point * b.digits_after_point

    std::vector<unsigned char> result;
    BCD result_1, result_2, result_3, result_4;

    result_1.digits_after_point = bcd_mul(a.digits_before_point, b.digits_before_point);
    
    int digits_after_point_result_2 = b.digits_after_point.size();
    result = bcd_mul(a.digits_before_point, b.digits_after_point);
    result_2.digits_before_point = std::vector<unsigned char>(result.end() - digits_after_point_result_2, result.end());
    result_2.digits_after_point = std::vector<unsigned char>(result.begin(), result.end() - digits_after_point_result_2);

    result = bcd_mul(a.digits_after_point, b.digits_before_point);
    int digits_after_point_result_3 = a.digits_after_point.size();
    result_3.digits_before_point = std::vector<unsigned char>(result.end() - digits_after_point_result_3, result.end());
    result_3.digits_after_point = std::vector<unsigned char>(result.begin(), result.end() - digits_after_point_result_3);

    result = bcd_mul(a.digits_after_point, b.digits_after_point);
    int digits_after_point_result_4 = a.digits_after_point.size() + b.digits_after_point.size();
    result_4.digits_before_point = std::vector<unsigned char>(result.end() - digits_after_point_result_4, result.end());
    result_4.digits_after_point = std::vector<unsigned char>(result.begin(), result.end() - digits_after_point_result_4);


    BCD temp1 = add_bcd(result_1, result_2);
    BCD temp2 = add_bcd(result_3, result_4);

    return add_bcd(temp1, temp2);
}


#endif
