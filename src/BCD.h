#ifndef BCD_H
#define BCD_H

#include <vector>


struct BCD {
    std::vector<unsigned char> digits_before_point;
    std::vector<unsigned char> digits_after_point;
};


#endif
