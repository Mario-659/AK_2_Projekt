#include "BCD.h"

std::string BCD::to_string_in_decimal() const {
    std::ostringstream oss;

    for(auto digit : digits_before_point) {
        oss << static_cast<int>(digit);
    }

    oss << '.';

    for(auto digit : digits_after_point) {
        oss << static_cast<int>(digit);
    }

    return oss.str();
}
