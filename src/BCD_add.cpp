#include "BCD_add.h"

BCD add_bcd(const BCD& a, const BCD& b) {
    BCD result;

    int length_before_point = std::max(a.digits_after_point.size(), b.digits_after_point.size());
    result.digits_after_point.resize(length_before_point, 0);

    int floating_point_diff = a.digits_after_point.size() - b.digits_after_point.size();

    // Copy digits after point
    if (floating_point_diff > 0) {
        std::copy(a.digits_after_point.end() - floating_point_diff, a.digits_after_point.end(),
                  result.digits_after_point.end() - floating_point_diff);
    } else if (floating_point_diff < 0) {
        floating_point_diff = -floating_point_diff;
        std::copy(b.digits_after_point.end() - floating_point_diff, b.digits_after_point.end(),
                  result.digits_after_point.end() - floating_point_diff);
    }

    unsigned char carry = 0;
    for (int i = length_before_point - floating_point_diff - 1; i >= 0; --i) {
        unsigned char digitA = a.digits_after_point[i];
        unsigned char digitB = b.digits_after_point[i];
        unsigned char sum = digitA + digitB;

        __asm__(
            "add %2, %0\n\t"
            "aaa\n\t"
            "mov %%ah, %1"
            : "+a"(sum), "=r"(carry)
            : "r"(carry)
            : "cc"
        );

        result.digits_after_point[i] = sum;
    }


    int length_after_point = std::max(a.digits_before_point.size(), b.digits_before_point.size());
    result.digits_before_point.resize(length_after_point, 0);

    for (int i = a.digits_before_point.size() - 1, j = b.digits_before_point.size() - 1, k = length_after_point - 1; i >= 0 || j >= 0; --i, --j, --k) {
        
        unsigned char digitA = (i >= 0) ? a.digits_before_point[i] : 0;
        unsigned char digitB = (j >= 0) ? b.digits_before_point[j] : 0;
        unsigned char sum = digitA + digitB;

        __asm__(
            "add %2, %0\n\t"
            "aaa\n\t"
            "mov %%ah, %1"
            : "+a"(sum), "=r"(carry)
            : "r"(carry)
            : "cc"
        );

        result.digits_before_point[k] = sum;
    }

    // Add the carry to the result
    if (carry != 0) {
        result.digits_before_point.insert(result.digits_before_point.begin(), carry);
    }

    return result;
}

std::vector<unsigned char> bcd_add(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b) {
    std::vector<unsigned char> result;

    int length_after_point = std::max(a.size(), b.size());
    result.resize(length_after_point, 0);

    unsigned char carry = 0;
    for (int i = a.size() - 1, j = b.size() - 1, k = length_after_point - 1; i >= 0 || j >= 0; --i, --j, --k) {
        
        unsigned char digitA = (i >= 0) ? a[i] : 0;
        unsigned char digitB = (j >= 0) ? b[j] : 0;
        unsigned char sum = digitA + digitB;

        __asm__(
            "add %2, %0\n\t"
            "aaa\n\t"
            "mov %%ah, %1"
            : "+a"(sum), "=r"(carry)
            : "r"(carry)
            : "cc"
        );

        result[k] = sum;
    }

    // Add the carry to the result
    if (carry != 0) {
        result.insert(result.begin(), carry);
    }

    return result;
}
