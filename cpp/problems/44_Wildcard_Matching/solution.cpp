//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
    https://leetcode.com/problems/wildcard-matching/
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        auto string_length = s.length();
        auto pattern_length = p.length();

        vector<vector<bool>> match(pattern_length + 1, vector<bool>(string_length + 1, false));
        match[0][0] = true;

        for (int i = 1; i < pattern_length + 1; i++) {
            auto pattern_char = p[i-1];
            match[i][0] = match[i-1][0] && pattern_char=='*';

            for (int j = 1; j < string_length + 1; j++) {
                auto s_char = s[j-1];
                if (pattern_char == '*') {
                    match[i][j] = match[i-1][j] || match[i][j-1];
                } else {
                    match[i][j] = match[i-1][j-1] && (pattern_char == '?' || pattern_char == s_char);
                }
            }
        }

        return match[pattern_length][string_length];
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

TEST_CASE("WildcardMatching") {
    auto res = Solution().isMatch("aa", "a");
    REQUIRE(!res);

    res = Solution().isMatch("adceb", "*a*b");
    REQUIRE(res);
}

