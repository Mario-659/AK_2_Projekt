#ifndef BCD_ADD_H
#define BCD_ADD_H

#include <utility>
#include <iostream>
#include <algorithm>

#include "BCD.h"

BCD add_bcd(const BCD& a, const BCD& b);

std::vector<unsigned char> bcd_add(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b);

#endif