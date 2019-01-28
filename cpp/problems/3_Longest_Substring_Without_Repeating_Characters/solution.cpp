//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
    
        auto length_map = map<char, int>();
        auto max_length = 0, current_max = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if (length_map.find(s[i]) != length_map.end()) {
                auto last_same_index = length_map[s[i]];
                current_max = min(current_max+1, i - last_same_index);
            } else {
                current_max ++;
            }
            
            max_length = max(max_length, current_max);
            length_map[s[i]] = i;
        }
        
        return max_length;
    }
};

TEST_CASE("LongestSubstringWithoutRepeatingCharacters") {
    auto res = Solution().lengthOfLongestSubstring("abcabcbb");
    REQUIRE( res == 3);

    res = Solution().lengthOfLongestSubstring("bbbbb");
    REQUIRE( res == 1);

    res = Solution().lengthOfLongestSubstring("pwwkew");
    REQUIRE( res == 3);
}

