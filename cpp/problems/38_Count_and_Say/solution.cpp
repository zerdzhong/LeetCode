//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <string>

using namespace std;

/*
    https://leetcode.com/problems/count-and-say/
    Write a program to solve a Sudoku puzzle by filling the empty cells.
 */

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string result;
        string previous = countAndSay(n-1);
        auto length = previous.length();
        char same_count = '1';
        for (int i = 0; i < length; i++) {
            if( i + 1 < length && previous[i] == previous[i+1]) {
                same_count ++;
            } else {
                result += string{same_count} + string{previous[i]};
                same_count = '1';
            }
        }

        return result;
    }
};


TEST_CASE("CountAndSay") {
    auto res = Solution().countAndSay(1);
    REQUIRE(res == "1");

    res = Solution().countAndSay(4);
    REQUIRE(res == "1211");

    res = Solution().countAndSay(5);
    REQUIRE(res == "111221");
}

