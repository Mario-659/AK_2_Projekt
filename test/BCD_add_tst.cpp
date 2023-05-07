#include "gtest/gtest.h"
#include "BCD_add.h"

#include <vector>

TEST(BCDAdditionTest, should_add_two_numbers_without_carry) {
    BCD a, b, result;

    a.digits_before_point = {0x03};
    a.digits_after_point = {0x05};

    b.digits_before_point = {0x02};
    b.digits_after_point = {0x04};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x05}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x09}));
}


TEST(BCDAdditionTest, should_add_two_numbers_with_carry_1) {
    BCD a, b, result;

    a.digits_before_point = {0x03};
    a.digits_after_point = {0x05};

    b.digits_before_point = {0x02};
    b.digits_after_point = {0x06};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x05}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01, 0x01}));
}


TEST(BCDAdditionTest, should_add_two_numbers_with_carry_2) {
    BCD a, b, result;

    a.digits_before_point = {0x08};
    a.digits_after_point = {0x07};

    b.digits_before_point = {0x05};
    b.digits_after_point = {0x04};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x03}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01, 0x02}));
}


TEST(BCDAdditionTest, should_add_two_numbers_with_carry_and_floating_point) {
    BCD a, b, result;

    a.digits_before_point = {0x05};
    a.digits_after_point = {0x03, 0x02, 0x01};

    b.digits_before_point = {0x03};
    b.digits_after_point = {0x04, 0x05};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x08}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x03, 0x06, 0x06}));
}


TEST(BCDAdditionTest, should_add_two_numbers_with_carry_and_floating_point_2) {
    BCD a, b, result;

    a.digits_before_point = {0x03};
    a.digits_after_point = {0x04, 0x05};

    b.digits_before_point = {0x05};
    b.digits_after_point = {0x03, 0x02, 0x01};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x08}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x03, 0x06, 0x06}));
}


TEST(BCDAdditionTest, should_add_two_numbers_with_same_length_and_no_carry) {
    BCD a, b, result;

    a.digits_before_point = {0x01};
    a.digits_after_point = {0x02, 0x03};

    b.digits_before_point = {0x05};
    b.digits_after_point = {0x06, 0x06};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x06}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x08, 0x09}));
}


TEST(BCDAdditionTest, should_add_two_numbers_with_different_length_and_no_carry) {
    BCD a, b, result;

    a.digits_before_point = {0x01};
    a.digits_after_point = {0x02, 0x03};

    b.digits_before_point = {0x05, 0x06};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x06, 0x06}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x02, 0x03}));
}

TEST(BCDAdditionTest, should_add_two_numbers_with_different_length_and_no_carry_inv) {
    BCD a, b, result;

    a.digits_before_point = {0x01};
    a.digits_after_point = {0x02, 0x03};

    b.digits_before_point = {0x05, 0x06};

    result = add_bcd(b, a);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x06, 0x06}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x02, 0x03}));
}


TEST(BCDAdditionTest, should_add_two_numbers_with_same_digits_and_same_floating_point) {
    BCD a, b, result;

    a.digits_before_point = {0x01};
    a.digits_after_point = {0x02, 0x03};

    b.digits_before_point = {0x01};
    b.digits_after_point = {0x02, 0x03};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x02}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x04, 0x06}));
}


TEST(BCDAdditionTest, BCDAdditionTest_should_add_two_numbers_with_different_length_and_carry_2) {
    BCD a, b, result;

    a.digits_before_point = {0x03};
    a.digits_after_point = {0x01, 0x05, 0x01};

    b.digits_before_point = {0x01, 0x07};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{0x04, 0x07}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01, 0x05, 0x01}));
}

TEST(BCDAdditionTest, BCDAdditionTest_should_add_two_numbers_with_no_digits_before_point) {
    BCD a, b, result;

    
    a.digits_after_point = {0x01};

    b.digits_after_point = {0x01, 0x07};

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits_before_point, (std::vector<unsigned char>{}));
    EXPECT_EQ(result.digits_after_point, (std::vector<unsigned char>{0x01, 0x08}));
}

