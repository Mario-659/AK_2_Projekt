#include <chrono>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>

#include "BCD.h"

class BCDPerformanceTester {
private:
    std::vector<BCD> test_cases_a;
    std::vector<BCD> test_cases_b;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

    std::ofstream log_file;

public:
    BCDPerformanceTester() 
        : distribution(0, 9), 
          log_file("results.csv") { }

    void generate_test_cases_ascending_sizes(size_t test_cases_count) {
        for (size_t i = 1; i <= test_cases_count; ++i) {
            BCD a = generate_random_bcd(i, i), b = generate_random_bcd(i, i);

            // test_cases_a[x] should be greater or equal to test_cases_b[x] because subtraction does not handle negative numbers
            if (a > b) {
                test_cases_a.push_back(a);
                test_cases_b.push_back(b);
            } else {
                test_cases_a.push_back(b);
                test_cases_b.push_back(a);
            }
        }
    }

    BCD generate_random_bcd(size_t size_before_point, size_t size_after_point) {
        BCD bcd;

        for (size_t i = 0; i < size_before_point; ++i) {
            bcd.digits_before_point.push_back(distribution(generator));
        }

        for (size_t i = 0; i < size_after_point; ++i) {
            bcd.digits_after_point.push_back(distribution(generator));
        }

        while(bcd.digits_before_point.front() == 0 && bcd.digits_before_point.size() > 1) {
            bcd.digits_before_point.erase(bcd.digits_before_point.begin());
        }

        return bcd;
    }
        

    void test_add_bcd() {
        size_t total = test_cases_a.size();

        for (size_t i = 0; i < test_cases_a.size(); i++) {
            BCD a = test_cases_a[i], b = test_cases_b[i];


            auto start = std::chrono::high_resolution_clock::now();
            BCD result = add(a, b);
            auto end = std::chrono::high_resolution_clock::now();
            
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            log_result(a, b, duration.count());
            
            float progress = ((float)i / (float)total) * 100.0f;
            std::cout << "\rProgress: " << std::fixed << std::setprecision(2) << progress << "% " << std::flush;
        }
        std::cout << std::endl;
    }

    void test_sub_bcd() {
        size_t total = test_cases_a.size();

        for (size_t i = 0; i < test_cases_a.size(); i++) {
            BCD a = test_cases_a[i], b = test_cases_b[i];

            auto start = std::chrono::high_resolution_clock::now();
            BCD result = subtract(a, b);
            auto end = std::chrono::high_resolution_clock::now();
            
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            log_result(a, b, duration.count());

            float progress = ((float)i / (float)total) * 100.0f;
            std::cout << "\rProgress: " << std::fixed << std::setprecision(2) << progress << "% " << std::flush;
        }
        std::cout << std::endl;
    }

    void test_mul_bcd() {
        size_t total = test_cases_a.size();

        for (size_t i = 0; i < total; i++) {
            BCD a = test_cases_a[i], b = test_cases_b[i];

            auto start = std::chrono::high_resolution_clock::now();
            BCD result = multiply(a, b);
            auto end = std::chrono::high_resolution_clock::now();
            
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            log_result(a, b, duration.count());

            float progress = ((float)i / (float)total) * 100.0f;
            std::cout << "\rProgress: " << std::fixed << std::setprecision(2) << progress << "% " << std::flush;
        }
        std::cout << std::endl;
    }

    void log_header() {
        log_file << "a_size,b_size,duration(nanoseconds)\n";
    }

    void log_result(BCD a, BCD b, int64_t duration) {
        unsigned int a_size_before_point_size = a.digits_before_point.size();
        unsigned int a_size_after_point_size = a.digits_after_point.size();
        unsigned int a_size = a_size_before_point_size + a_size_after_point_size;

        unsigned int b_size_before_point_size = b.digits_before_point.size();
        unsigned int b_size_after_point_size = b.digits_after_point.size();
        unsigned int b_size = b_size_before_point_size + b_size_after_point_size;

        log_file << a_size << "," << b_size << "," << duration << "\n";
    }


};
