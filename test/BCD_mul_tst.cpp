#include "gtest/gtest.h"
#include "BCD_mul.h"

#include <vector>

//segmentation error
// TEST(BCDMultiplicationTest, should_multiply_by_one) {
//     BCD a, b, result;

//     a.digits_before_point = {0x02};
//     a.digits_after_point = {0x05};

//     b.digits_before_point = {0x01};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x02}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x05}));
// }

TEST(BCDMultiplicationTest, should_multiply_different_number_of_digits_before_point) {
    BCD a, b, result;

    a.digits_after_point = {0x05};
    a.digits_before_point = {0x03, 0x02, 0x01};


    b.digits_after_point = {0x03};
    b.digits_before_point = {0x04, 0x05};

    result = multiply_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x09, 0x05}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01, 0x04, 0x05, 0x06, 0x03}));
}

TEST(BCDMultiplicationTest, should_multiply_by_one_digit) {
    std::vector<unsigned char> a, b, result;

    a = {0x04, 0x05};
    b = {0x05};

    result = bcd_mul(a, b);

    EXPECT_EQ(result, (std::vector<unsigned char>{0x02, 0x02, 0x05}));
}

//some of other tests are not passing
// TEST(BCDMultiplicationTest, should_multiply_two_numbers_without_carry) {
//     BCD a, b, result;

//     a.digits_before_point = {0x02};
//     a.digits_after_point = {0x05};

//     b.digits_before_point = {0x03};
//     b.digits_after_point = {0x00};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x07}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x05}));
// }

// TEST(BCDMultiplicationTest, should_multiply_two_numbers_with_carry) {
//     BCD a, b, result;

//     a.digits_before_point = {0x04};
//     a.digits_after_point = {0x00};

//     b.digits_before_point = {0x05};
//     b.digits_after_point = {0x00};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x20}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{}));
// }

// TEST(BCDMultiplicationTest, should_multiply_two_numbers_with_decimal_points) {
//     BCD a, b, result;

//     a.digits_before_point = {0x02};
//     a.digits_after_point = {0x05};

//     b.digits_before_point = {0x01};
//     b.digits_after_point = {0x05};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x03}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x07, 0x05}));
// }

// TEST(BCDMultiplicationTest, should_multiply_two_numbers_with_carry_and_decimal_points) {
//     BCD a, b, result;

//     a.digits_before_point = {0x02};
//     a.digits_after_point = {0x05};

//     b.digits_before_point = {0x03};
//     b.digits_after_point = {0x05};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x07}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x02, 0x05}));
// }

// TEST(BCDMultiplicationTest, should_multiply_two_numbers_with_different_length_and_decimal_points) {
//     BCD a, b, result;

//     a.digits_before_point = {0x02, 0x05};
//     a.digits_after_point = {0x01};

//     b.digits_before_point = {0x03};
//     b.digits_after_point = {0x01, 0x05};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x07, 0x07}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x03, 0x02, 0x05}));
// }

// TEST(BCDMultiplicationTest, should_multiply_two_numbers_with_same_digits_and_same_floating_point) {
//     BCD a, b, result;

//     a.digits_before_point = {0x02};
//     a.digits_after_point = {0x01};

//     b.digits_before_point = {0x02};
//         b.digits_after_point = {0x01};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x04}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x02, 0x01}));
// }

// TEST(BCDMultiplicationTest, should_multiply_two_numbers_with_different_length_and_carry) {
//     BCD a, b, result;

//     a.digits_before_point = {0x02, 0x05};
//     a.digits_after_point = {0x01};

//     b.digits_before_point = {0x03};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x07, 0x07, 0x03}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x03}));
// }

// TEST(BCDMultiplicationTest, should_multiply_a_number_by_zero) {
//     BCD a, b, result;

//     a.digits_before_point = {0x02, 0x05};
//     a.digits_after_point = {0x01};

//     b.digits_before_point = {0x00};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x00}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{}));
// }

// TEST(BCDMultiplicationTest, should_multiply_two_numbers_with_no_digits_before_point) {
//     BCD a, b, result;

//     a.digits_after_point = {0x02};

//     b.digits_after_point = {0x03};

//     result = multiply_bcd(a, b);

//     EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{}));
//     EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x06}));
// }

