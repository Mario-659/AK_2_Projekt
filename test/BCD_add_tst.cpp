#include "gtest/gtest.h"
#include "BCD_add.h"

#include <vector>

TEST(BCDAdditionTest, should_add_two_numbers_without_carry) {
    BCD a, b, result;

    a.digits = {0x03, 0x05};
    a.floating_point_position = 0;

    b.digits = {0x02, 0x04};
    b.floating_point_position = 0;

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits, (std::vector<unsigned char>{0x05, 0x09}));
    EXPECT_EQ(result.floating_point_position, 0);
}

TEST(BCDAdditionTest, should_add_two_numbers_with_carry_1) {
    BCD a, b, result;

    a.digits = {0x03, 0x05};
    a.floating_point_position = 0;

    b.digits = {0x02, 0x06};
    b.floating_point_position = 0;

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits, (std::vector<unsigned char>{0x06, 0x01}));
    EXPECT_EQ(result.floating_point_position, 0);
}

TEST(BCDAdditionTest, should_add_two_numbers_with_carry_2) {
    BCD a, b, result;

    a.digits = {0x08, 0x07};
    a.floating_point_position = 0;

    b.digits = {0x05, 0x04};
    b.floating_point_position = 0;

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits, (std::vector<unsigned char>{0x01, 0x04, 0x01}));
    EXPECT_EQ(result.floating_point_position, 0);
}

TEST(BCDAdditionTest, should_add_two_numbers_with_carry_and_floating_point) {
    BCD a, b, result;

    a.digits = {0x05, 0x03, 0x02, 0x01};
    a.floating_point_position = 2;

    b.digits = {0x03, 0x04, 0x05};
    b.floating_point_position = 1;

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits, (std::vector<unsigned char>{0x08, 0x07, 0x07, 0x01}));
    EXPECT_EQ(result.floating_point_position, 2);
}

TEST(BCDAdditionTest, should_add_two_numbers_with_carry_and_floating_point_2) {
    BCD a, b, result;

    a.digits = {0x03, 0x04, 0x05};
    a.floating_point_position = 1;

    b.digits = {0x05, 0x03, 0x02, 0x01};
    b.floating_point_position = 2;

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits, (std::vector<unsigned char>{0x08, 0x07, 0x07, 0x01}));
    // EXPECT_EQ(result.floating_point_position, 2);
}

TEST(BCDAdditionTest, should_add_two_numbers_with_same_length_and_no_carry) {
    BCD a, b, result;

    a.digits = {0x01, 0x02, 0x03};
    a.floating_point_position = 1;

    b.digits = {0x05, 0x06, 0x06};
    b.floating_point_position = 1;

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits, (std::vector<unsigned char>{0x06, 0x08, 0x09}));
    EXPECT_EQ(result.floating_point_position, 1);
}

TEST(BCDAdditionTest, should_add_two_numbers_with_different_length_and_no_carry) {
    BCD a, b, result;

    a.digits = {0x01, 0x02, 0x03};
    a.floating_point_position = 1;

    b.digits = {0x05, 0x06};
    b.floating_point_position = 0;

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits, (std::vector<unsigned char>{0x06, 0x08, 0x03}));
    EXPECT_EQ(result.floating_point_position, 1);
}

TEST(BCDAdditionTest, should_add_two_numbers_with_same_digits_and_same_floating_point) {
    BCD a, b, result;

    a.digits = {0x01, 0x02, 0x03};
    a.floating_point_position = 1;

    b.digits = {0x01, 0x02, 0x03};
    b.floating_point_position = 1;

    result = add_bcd(a, b);

    EXPECT_EQ(result.digits, (std::vector<unsigned char>{0x02, 0x04, 0x06}));
    EXPECT_EQ(result.floating_point_position, 1);
}

TEST(BCDAdditionTest, BCDAdditionTest_should_add_two_numbers_with_different_length_and_carry_2) {
    BCD a, b, result;

    a.digits = {0x03, 0x00, 0x00, 0x00, 0x01};
    a.floating_point_position = 4;

    b.digits = {0x01, 0x07};
    b.floating_point_position = 0;

    result = add_bcd(a, b);

    // EXPECT_EQ(result.digits, (std::vector<unsigned char>{0x01, 0x07, 0x00, 0x00, 0x00, 0x01}));
    // EXPECT_EQ(result.floating_point_position, 4);
}

