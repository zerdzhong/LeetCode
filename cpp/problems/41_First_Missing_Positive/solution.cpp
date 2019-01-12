//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
    https://leetcode.com/problems/first-missing-positive/
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto nums_count = nums.size();
        // make all num positive
        for (auto &num : nums) {
            if (num <= 0 || num > nums_count) { num = INT_MAX; }
        }

        //use negative index indicate num in array
        for (int i = 0; i < nums_count; i++) {
            if (abs(nums[i]) == INT_MAX) {
                continue;
            }

            auto index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        //first negative index is min num
        for (int i = 0; i < nums_count; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return static_cast<int>(nums_count);
    }
};

TEST_CASE("FirstMissingPositive") {
    vector<int> nums = {3,4,-1,1};
    auto res = Solution().firstMissingPositive(nums);
    REQUIRE(res == 2);

    nums = {7,8,9,11,2};
    res = Solution().firstMissingPositive(nums);
    REQUIRE(res == 1);

}

