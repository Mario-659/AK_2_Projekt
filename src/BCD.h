#ifndef BCD_H
#define BCD_H

#include <vector>
#include <cstdio>
#include <stdexcept>
#include <sstream>
#include <iomanip>

/**
 * The BCD struct represents a Binary Coded Decimal number. It has two fields:
 * digits_before_point: represents the digits before the decimal point in a BCD number.
 * digits_after_point: represents the digits after the decimal point in a BCD number.
 */
struct BCD {
    std::vector<unsigned char> digits_before_point;
    std::vector<unsigned char> digits_after_point;

    /**
     * Constructs a new unpacked BCD (Binary Coded Decimal) number from a string representation of a decimal number.
     *
     * @param decimal_representation: A string representing a decimal number. Example: "123.456"
     * 
     * @return BCD: A new BCD object representing the decimal number given in the input string.
     */
    BCD(const std::string& decimal_representation);

    /**
     * Initializes a new empty BCD number.
     *
     * @return BCD: A new, empty BCD number.
     */
    BCD() = default;

    /**
     * Converts an unpacked BCD number to a string in decimal format.
     *
     * @return std::string: String representation of the BCD number in decimal format.
     */
    std::string to_string_in_decimal() const;

    /**
     * Converts an unpacked BCD number to a string in hexadecimal format.
     *
     * @return std::string: String representation of the BCD number in hexadecimal format.
     */
    std::string to_string_in_hexadecimal() const;
};

/**
 * Performs addition operation on two unpacked BCD (Binary Coded Decimal) numbers.
 *
 * @param a: First BCD number.
 * @param b: Second BCD number.
 *
 * The function aligns the two BCD numbers by their decimal points,
 * and then adds them digit by digit from right to left using assembly instructions to handle BCD addition.
 * If the sum of two digits is more than 9, a carry is generated and added to the next higher digit.
 *
 * @return BCD: Result of the addition operation.
 */
BCD add(const BCD& a, const BCD& b);

/**
 * Performs addition operation on two unpacked BCD numbers represented as vectors of unsigned chars.
 *
 * @param a: First unpacked BCD number represented as a vector of unsigned chars.
 * @param b: Second unpacked BCD number represented as a vector of unsigned chars.
 *
 * The function bcd_add adds two vectors digit by digit from right to left using assembly instructions to handle BCD addition.
 * If the sum of two digits is more than 9, a carry is generated and added to the next higher digit.
 *
 * @return std::vector<unsigned char>: Result of the addition operation represented as a vector of unsigned chars.
 */
std::vector<unsigned char> add(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b);

/**
 * Performs subtraction operation on two unpacked BCD (Binary Coded Decimal) numbers.
 *
 * @param a: First BCD number (minuend).
 * @param b: Second BCD number (subtrahend).
 *
 * The function sub_BCD aligns the two BCD numbers by their decimal points,
 * and then subtracts them digit by digit from right to left using assembly instructions to handle BCD subtraction.
 * If the subtrahend digit is more than the minuend digit, a borrow is generated from the next higher digit.
 *
 * @return BCD: Result of the subtraction operation. 
 *              Throws an underflow_error if the minuend is smaller than the subtrahend.
 */
BCD subtract(const BCD& a, const BCD& b);

/**
 * Perform multiplication operation on two unpacked BCD numbers represented as vectors of unsigned chars.
 *
 * @param a: First BCD number represented as a vector of unsigned chars.
 * @param b: Second BCD number represented as a vector of unsigned chars.
 *
 * The implementation of this function is not provided here, and the function's exact behavior depends on its implementation.
 *
 * @return std::vector<unsigned char>: Expected to return result of the multiplication operation represented as a vector of unsigned chars.
 */
std::vector<unsigned char> multiply(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b);

/**
 * Performs multiplication operation on two unpacked BCD (Binary Coded Decimal) numbers.
 *
 * @param a: First BCD number.
 * @param b: Second BCD number.
 *
 * The function multiply takes two BCD numbers as input and returns their product.
 * The exact behavior of the function depends on its implementation.
 *
 * @return BCD: Result of the multiplication operation. 
 */
BCD multiply(const BCD& a, const BCD& b);

#endif
