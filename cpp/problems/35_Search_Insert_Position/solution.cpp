//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
 */


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto nums_size = nums.size();
        if (nums_size == 0) { return 0; }

        int start_index = 0, end_index = static_cast<int>(nums_size - 1), mid_index = 0;

        while (start_index <= end_index) {
            mid_index = start_index + (end_index - start_index) / 2;
            auto mid_value = nums[mid_index];

            if (mid_value < target) {
                start_index = mid_index + 1;
            } else if (mid_value > target) {
                end_index = mid_index - 1;
            } else {
                return mid_index;
            }
        }

        if (end_index < 0) {
            return 0;
        } else if(start_index >= nums_size) {
            return static_cast<int>(nums_size - 1);
        }

        if (target > nums[end_index] ) {
            return end_index + 1;
        } else {
            return end_index;
        }
    }
};

TEST_CASE("SearchInsertPosition") {
    vector<int> nums = {1,3,5,6};
    auto res = Solution().searchInsert(nums, 5);
    REQUIRE( res == 2);

    res = Solution().searchInsert(nums, 0);
    REQUIRE( res == 0);

    res = Solution().searchInsert(nums, 2);
    REQUIRE( res == 1);

    res = Solution().searchInsert(nums, 7);
    REQUIRE( res == 4);
}

