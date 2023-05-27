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

BCD::BCD(const std::string& number_string) {
    size_t i;
    for (i = 0; i < number_string.size(); ++i) {
        if (isdigit(number_string[i])) {
            digits_before_point.push_back(number_string[i] - '0');
        }
        else if (number_string[i] == '.') {
            break;
        }
    }
    for(; i< number_string.size(); ++i) {
        if (isdigit(number_string[i])) {
            digits_after_point.push_back(number_string[i] - '0');
        }
    }
}
