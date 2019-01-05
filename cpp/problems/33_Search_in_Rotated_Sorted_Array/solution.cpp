//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
18 19 20 30 31 0 1 5 8 9 10 11 12 13

 18 19 20 30 31 32 33 1 2 3
 */


class Solution {
public:
    //binary search like solution
    int search(vector<int>& nums, int target) {
        size_t nums_size = nums.size();
        if (nums_size == 0) return -1;
        if (nums_size == 1) return nums[0] == target ? 0 : -1;

        int mid = 0, mid_index = 0, start_index = 0, end_index = static_cast<int>(nums_size - 1);
        int first_value = nums[0];

        while (start_index <= end_index) {
            mid_index = start_index + (end_index - start_index) / 2;
            mid = nums[mid_index];
            if (mid < target) {
                if (mid < first_value && target >= first_value) {
                    end_index = mid_index - 1;
                } else {
                    start_index = mid_index + 1;
                }
            } else if (mid > target) {
                if (mid >= first_value && target < first_value) {
                    start_index = mid_index + 1;
                } else {
                    end_index = mid_index - 1;
                }
            } else {
                return mid_index;
            }
        }

        return -1;
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

TEST_CASE("SearchRotatedSortedArray") {
    vector<int> nums = {4,5,6,7,0,1,2};
    auto res = Solution().search(nums, 0);
    REQUIRE( res == 4);

    nums = {4,5,6,7,0,1,2};
    res = Solution().search(nums, 7);
    REQUIRE( res == 3);

    nums = {5,1,3};
    res = Solution().search(nums, 5);
    REQUIRE( res == 0);
}

