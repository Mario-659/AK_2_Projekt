#include <iostream>

#include "BCDPerformanceTester.h"


int main(int argc, char const *argv[])
{
    BCDPerformanceTester tester;

    tester.generate_test_cases_ascending_sizes(10000);
    tester.log_header();
    tester.test_sub_bcd();

    return 0;
}
