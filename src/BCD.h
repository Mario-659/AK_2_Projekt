#ifndef BCD_H
#define BCD_H

#include <vector>
#include <cstdio>
#include <stdexcept>

struct BCD {
    std::vector<unsigned char> digits_before_point;
    std::vector<unsigned char> digits_after_point;
};

BCD add_bcd(const BCD& a, const BCD& b);

std::vector<unsigned char> bcd_add(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b);

BCD sub_BCD(const BCD& a, const BCD& b);

std::vector<unsigned char> bcd_mul(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b);

BCD multiply_bcd(const BCD& a, const BCD& b);

inline void printBCD(BCD bcd) {
    for (auto digit : bcd.digits_before_point) {
        printf("%x", digit);
    }
    printf(".");
    for (auto digit : bcd.digits_after_point) {
        printf("%x", digit);
    }
    printf("\n");
}

#endif
