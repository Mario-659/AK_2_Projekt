#include "gtest/gtest.h"
#include "BCD.h"

TEST(BCDSubtractionTest, test_case_one) {
    BCD a, b, result;

    a.digits_before_point = {0x07, 0x05};
    a.digits_after_point = {0x01};

    b.digits_before_point = {0x02, 0x03};
    b.digits_after_point = {};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x05, 0x02}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01}));
}

TEST(BCDSubtractionTest, test_case_two) {
    BCD a, b, result;

    a.digits_before_point = {0x01, 0x00};
    a.digits_after_point = {0x05};

    b.digits_before_point = {0x09};
    b.digits_after_point = {};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x01}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x05}));
}

TEST(BCDSubtractionTest, test_case_three) {
    BCD a, b, result;

    a.digits_before_point = {0x03, 0x05};
    a.digits_after_point = {0x04, 0x01};

    b.digits_before_point = {0x01, 0x02};
    b.digits_after_point = {0x01, 0x01};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x02, 0x03}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x03, 0x00}));
}

TEST(BCDSubtractionTest, test_case_four) {
    BCD a, b;

    a.digits_before_point = {0x01, 0x00};
    a.digits_after_point = {0x00};

    b.digits_before_point = {0x02, 0x00};
    b.digits_after_point = {0x00};

    EXPECT_THROW(subtract(a, b), std::underflow_error);
}

TEST(BCDSubtractionTest, test_case_five) {
    BCD a, b, result;

    a.digits_before_point = {0x09, 0x09};
    a.digits_after_point = {0x09, 0x09};

    b.digits_before_point = {0x00, 0x01};
    b.digits_after_point = {0x00, 0x01};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x09, 0x08}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x09, 0x08}));
}


TEST(BCDSubtractionTest, should_subtract_two_numbers_with_same_length_no_borrow) {
    BCD a, b, result;

    a.digits_before_point = {0x07, 0x05};
    a.digits_after_point = {};

    b.digits_before_point = {0x02, 0x03};
    b.digits_after_point = {};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x05, 0x02}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{}));
}

TEST(BCDSubtractionTest, should_subtract_two_numbers_with_borrow) {
    BCD a, b, result;

    a.digits_before_point = {0x05, 0x03};
    a.digits_after_point = {};

    b.digits_before_point = {0x02, 0x05};
    b.digits_after_point = {};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x02, 0x08}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{}));
}

TEST(BCDSubtractionTest, should_subtract_two_numbers_with_decimal_points) {
    BCD a, b, result;

    a.digits_before_point = {0x03, 0x07};
    a.digits_after_point = {0x04, 0x08};

    b.digits_before_point = {0x01, 0x05};
    b.digits_after_point = {0x02, 0x04};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x02, 0x02}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x02, 0x04}));
}

TEST(BCDSubtractionTest, should_handle_zero) {
    BCD a, b, result;

    a.digits_before_point = {0x00};
    a.digits_after_point = {};

    b.digits_before_point = {0x00};
    b.digits_after_point = {};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x00}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{}));
}

TEST(BCDSubtractionTest, should_handle_no_digits_before_point) {
    BCD a, b, result;

    a.digits_before_point = {};
    a.digits_after_point = {0x04, 0x07};

    b.digits_before_point = {};
    b.digits_after_point = {0x02, 0x03};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x02, 0x04}));
}

TEST(BCDSubtractionTest, should_handle_different_lengths) {
    BCD a, b, result;

    a.digits_before_point = {0x07, 0x05, 0x02};
    a.digits_after_point = {0x01};

    b.digits_before_point = {0x02, 0x03};
    b.digits_after_point = {0x00};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x07, 0x02, 0x09}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01}));
}

TEST(BCDSubtractionTest, should_subtract_numbers_with_same_digits_before_point) {
    BCD a, b, result;

    a.digits_before_point = {0x05, 0x03};
    a.digits_after_point = {0x04, 0x07};

    b.digits_before_point = {0x05, 0x03};
    b.digits_after_point = {0x02, 0x03};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x00}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x02, 0x04}));
}

TEST(BCDSubtractionTest, should_subtract_numbers_with_same_digits_after_point) {
    BCD a, b, result;

    a.digits_before_point = {0x07, 0x05};
    a.digits_after_point = {0x02, 0x04};

    b.digits_before_point = {0x02, 0x03};
    b.digits_after_point = {0x02, 0x04};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x05, 0x02}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x00, 0x00}));
}

TEST(BCDSubtractionTest, should_handle_no_digits_after_point_in_one_number) {
    BCD a, b, result;

    a.digits_before_point = {0x07, 0x05};
    a.digits_after_point = {0x02, 0x04};

    b.digits_before_point = {0x02, 0x03};
    b.digits_after_point = {};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x05, 0x02}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x02, 0x04}));
}

TEST(BCDSubtractionTest, should_handle_trailing_zeros_in_result) {
    BCD a, b, result;

    a.digits_before_point = {0x05, 0x03};
    a.digits_after_point = {0x02, 0x00};

    b.digits_before_point = {0x02, 0x03};
    b.digits_after_point = {0x01, 0x00};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x03, 0x00}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01, 0x00}));
}

TEST(BCDSubtractionTest, should_handle_leading_zeros_in_one_number) {
    BCD a, b, result;

    a.digits_before_point = {0x07, 0x05};
    a.digits_after_point = {0x02, 0x04};

    b.digits_before_point = {0x00, 0x03};
    b.digits_after_point = {0x01, 0x02};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x07, 0x02}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01, 0x02}));
}

TEST(BCDSubtractionTest, should_handle_large_numbers) {
    BCD a, b, result;

    a.digits_before_point = {0x09, 0x09, 0x09};
    a.digits_after_point = {0x09, 0x09};

    b.digits_before_point = {0x08, 0x08, 0x08};
    b.digits_after_point = {0x08, 0x08};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x01, 0x01, 0x01}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01, 0x01}));
}

TEST(BCDSubtractionTest, should_subtract_small_from_large) {
    BCD a, b, result;

    a.digits_before_point = {0x09, 0x09};
    a.digits_after_point = {0x09};

    b.digits_before_point = {0x01, 0x01};
    b.digits_after_point = {0x01};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x08, 0x08}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x08}));
}

TEST(BCDSubtractionTest, should_handle_only_digits_after_point) {
    BCD a, b, result;

    a.digits_before_point = {};
    a.digits_after_point = {0x09, 0x09};

    b.digits_before_point = {};
    b.digits_after_point = {0x08, 0x08};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01, 0x01}));
}

TEST(BCDSubtractionTest, should_handle_identical_numbers) {
    BCD a, b, result;

    a.digits_before_point = {0x09, 0x09};
    a.digits_after_point = {0x08, 0x08};

    b.digits_before_point = {0x09, 0x09};
    b.digits_after_point = {0x08, 0x08};

    result = subtract(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x00}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x00, 0x00}));
}
