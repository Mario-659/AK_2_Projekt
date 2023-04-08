#include "gtest/gtest.h"
#include "BCD_add.h"

TEST(bcd_adding, should_add_two_numbers){
    unsigned char number1 = 0x21;
    unsigned char number2 = 0x23;
    unsigned char result = bcd_add(number1, number2);

    EXPECT_TRUE(result == 0x44);
}
