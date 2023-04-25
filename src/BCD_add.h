#ifndef BCD_ADD_H
#define BCD_ADD_H

#include <utility>
#include <iostream>

#include "BCD.h"

// Adds two BCD numbers. Does not work with different floating point positions.
BCD add_bcd(const BCD& a, const BCD& b) {
    BCD result;
    result.floating_point_position = a.floating_point_position;

    int maxLength = std::max(a.digits.size(), b.digits.size());
    result.digits.resize(maxLength, 0);

    // std::cout << "size before adding: " << result.digits.size() << std::endl;

    unsigned char carry = 0;
    for (int i = maxLength-1; i >= 0; --i) {
        unsigned char digitA = (i < a.digits.size()) ? a.digits[i] : 0;
        unsigned char digitB = (i < b.digits.size()) ? b.digits[i] : 0;
        unsigned char sum = digitA + digitB;

        // std::cout << "digitA: " << (int)digitA << "\ndigitB: " << (int)digitB << "\nsum: " << (int)sum << "\ncarry: " << (int)carry << "\n" << std::endl;

        __asm__(
            "add %2, %0\n\t"
            "aaa\n\t"
            "mov %%ah, %1"
            : "+a"(sum), "=r"(carry)
            : "r"(carry)
            : "cc"
        );

        // std::cout << "after asm\nsum:" << (int)sum << "\ncarry:" << (int)carry << "\n\n\n" << std::endl;

        result.digits[i] = sum;
        
    }

    // Add the carry to the result
    if (carry != 0) {
        result.digits.insert(result.digits.begin(), carry);
    }

    // std::cout << result.digits.size() << std::endl;

    return result;
}


#endif