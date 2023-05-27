#ifndef BCD_SUB_H
#define BCD_SUB_H

#include <utility>
#include <iostream>
#include <algorithm>

#include "BCD.h"


inline BCD sub_BCD(const BCD& a, const BCD& b) {
    BCD result;

    int length_after_point = std::max(a.digits_after_point.size(), b.digits_after_point.size());
    result.digits_after_point.resize(length_after_point, 0);

    int floating_point_diff = a.digits_after_point.size() - b.digits_after_point.size();
    int rest_digits_after_point = length_after_point - floating_point_diff;

    unsigned char borrow = 0;
    if (floating_point_diff > 0) {
        std::copy(a.digits_after_point.end() - floating_point_diff, a.digits_after_point.end(),
                  result.digits_after_point.end() - floating_point_diff);
    } else if (floating_point_diff < 0) {
        //set borrow as 1, 10 at the last digit, 9 to the rest digits
        borrow = 1;
        floating_point_diff = -floating_point_diff - 1;
        result.digits_after_point[floating_point_diff] = 10 - b.digits_after_point[floating_point_diff];        
        floating_point_diff--;
        for (int i=floating_point_diff; i > 0; i--) {
            unsigned char diff = 9 - b.digits_after_point[i];
            result.digits_after_point[i] = diff;
        }
    }

    // adding the rest of digits after point
    for (int i = rest_digits_after_point - 1; i >= 0; i--) {
        
        unsigned char digitA = a.digits_after_point[i];
        unsigned char digitB = b.digits_after_point[i];
        unsigned char difference = digitA - digitB - borrow;

        __asm__(
            "aas\n\t"
            "mov %%ah, %1"
            : "+a"(difference), "=q"(borrow)
            : "r"(borrow)
            : "cc"
        );

        if (borrow > 0) borrow = 1;

        result.digits_after_point[i] = difference;
    }

    int before_point_length = std::max(a.digits_before_point.size(), b.digits_before_point.size());
    result.digits_before_point.resize(before_point_length, 0);

    for (int i = a.digits_before_point.size() - 1, j = b.digits_before_point.size() - 1, k = before_point_length - 1; i >= 0 || j >= 0; --i, --j, --k) {
        
        unsigned char digitA = (i >= 0) ? a.digits_before_point[i] : 0;
        unsigned char digitB = (j >= 0) ? b.digits_before_point[j] : 0;
        unsigned char difference = digitA - digitB - borrow;

        __asm__(
            "aas\n\t"
            "mov %%ah, %1"
            : "+a"(difference), "=q"(borrow)
            : "r"(borrow)
            : "cc"
        );

        if (borrow > 0) borrow = 1;        

        result.digits_before_point[k] = difference;
    }

    // If there's a borrow at the end, the minuend was smaller than the subtrahend, which is an error.
    if (borrow != 0) {
        throw std::underflow_error("The minuend is smaller than the subtrahend.");
    }

    // Remove leading zeroes
    while (result.digits_before_point.size() > 1 && result.digits_before_point[0] == 0) {
        result.digits_before_point.erase(result.digits_before_point.begin());
    }

    return result;
}



#endif // BCD_SUB_H
