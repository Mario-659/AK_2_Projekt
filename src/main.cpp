#include <iostream>

#include "BCD.h"


int main(int argc, char const *argv[])
{
    std::cout << "BCD (Binary Coded Decimal) Arithmetic Library Demonstration\n\n";

    BCD a("43.426"), b("29.2");

    std::cout << "Given BCD numbers are:\n";
    std::cout << "In a decimal representation:\n";
    std::cout << "a: " << a.to_string_in_decimal() << "\n";
    std::cout << "b: " << b.to_string_in_decimal() << "\n\n";
    
    std::cout << "In a hexadecimal representation:\n";
    std::cout << "a: " << a.to_string_in_hexadecimal() << "\n";
    std::cout << "b: " << b.to_string_in_hexadecimal() << "\n\n";

    BCD sum = a + b;
    std::cout << "The sum of 'a' and 'b' is: " << sum.to_string_in_decimal() << "\n\n";

    BCD difference = a - b;
    std::cout << "The difference of 'a' and 'b' is: " << difference.to_string_in_decimal() << "\n\n";

    BCD product = a * b;
    std::cout << "The product of 'a' and 'b' is: " << product.to_string_in_decimal() << "\n";


    return 0;
}
