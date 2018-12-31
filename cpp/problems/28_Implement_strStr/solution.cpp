//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return  0;
        }

        int same_length = 0;

        for (int i = 0; i < haystack.size(); ++i) {
            if (haystack[i] == needle[same_length]) {
                same_length ++;
                if (same_length == needle.size()) {
                    return i - same_length + 1;
                }
            } else if (same_length > 0){
                i = i - same_length;
                same_length = 0;
            }
        }

        return -1;
    }
};

TEST_CASE("ImplementStr") {

    string haystack = "mississippi", needle = "issip";
    auto res = Solution().strStr(haystack, needle);
    REQUIRE(res == 4);

    haystack = "mississippi", needle = "pi";
    res = Solution().strStr(haystack, needle);
    REQUIRE(res == 9);

    haystack = "hello", needle = "ll";
    res = Solution().strStr(haystack, needle);
    REQUIRE(res == 2);

    haystack = "aaaaa", needle = "bba";
    res = Solution().strStr(haystack, needle);
    REQUIRE(res == -1);


}

