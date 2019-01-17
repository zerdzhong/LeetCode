//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
    https://leetcode.com/problems/multiply-strings/
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        string result;

        auto num1_length = num1.length();
        auto num2_length = num2.length();
        auto result_digit = vector<int>(num1_length + num2_length);

        for (int i = 0; i < num1_length ; ++i) {
            for (int j = 0; j < num2_length ; ++j) {
                auto digit1 = num1[num1_length - 1 - i] - '0';
                auto digit2 = num2[num2_length - 1 - j] - '0';

                auto multiply_res = digit1 * digit2 + result_digit[i + j];

                result_digit[i + j] = multiply_res % 10;
                if (multiply_res / 10 > 0) {
                    result_digit[i + j + 1] += multiply_res / 10;
                }
            }
        }

        bool prefix_zero = true;
        for (int i = 0; i < num1_length + num2_length; ++i) {
            auto digit = result_digit[num1_length + num2_length - 1 - i];
            if (!prefix_zero || digit) {
                prefix_zero = false;
                result.push_back(digit + '0');
            }
        }

        return result.empty() ? "0" : result;
    }
};

TEST_CASE("MultiplyStrings", "multiply") {

    auto res = Solution().multiply("1234", "9");
    REQUIRE(res == "11106");

    res = Solution().multiply("123", "456");
    REQUIRE(res == "56088");

    res = Solution().multiply("1234", "0");
    REQUIRE(res == "0");
}

