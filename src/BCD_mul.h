#ifndef BCD_MUL_H
#define BCD_MUL_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "BCD.h"
#include "BCD_add.h"

std::vector<unsigned char> bcd_mul(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b);

BCD multiply_bcd(const BCD& a, const BCD& b);

#endif
