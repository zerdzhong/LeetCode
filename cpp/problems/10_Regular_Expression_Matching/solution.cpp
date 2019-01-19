//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
    https://leetcode.com/problems/regular-expression-matching/
 */

class Solution {
public:
    bool isMatch(string s, string p) {

        auto string_length = s.length();
        auto pattern_length = p.length();

        vector<vector<bool>> match(string_length + 1, vector<bool>(pattern_length + 1, false));
        match[0][0] = true;
        
        for(int i = 1; i < pattern_length + 1; i++)
        {
            if (p[i-1] == '*') {
                match[0][i] = match[0][i-2];
            }
        }
        
        
        for(int i = 1; i < string_length + 1; i++)
        {
            for(int j = 1; j < pattern_length + 1; j++)
            {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    match[i][j] = match[i-1][j-1];
                } else if (p[j-1] == '*'){
                    
                    if (p[j-2] != s[i-1] && p[j-2] != '.') {
                        // * match no occurence
                        match[i][j] = match[i][j-2];
                    } else {
                        match[i][j] = match[i][j-1] || match[i-1][j] || match[i][j-2];
                    }
                }
                
            }
             
        }
        
        return match[string_length][pattern_length];
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

TEST_CASE("RegularExpressionMatch") {
    auto res = Solution().isMatch("aab", "c*a*b*");
    REQUIRE(res == true);

    res = Solution().isMatch("mississippi", "mis*is*p*.");
    REQUIRE(res == false);

    res = Solution().isMatch("ab", ".*");
    REQUIRE(res == true);
}

