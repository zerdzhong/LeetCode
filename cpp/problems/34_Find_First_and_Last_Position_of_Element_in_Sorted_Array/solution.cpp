//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 */


class Solution {
public:
    //binary search like solution
    //Runtime: 8 ms, faster than 73.60% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
    vector<int> searchRange(vector<int>& nums, int target) {
        int end_index = static_cast<int>(nums.size() - 1);
        vector<int> result = {-1, -1};

        if (end_index < 0) {
            return result;
        }

        int start_index = 0, mid = 0, target_index = -1;

        while (start_index < end_index ) {
            if (nums[start_index] == nums[end_index]) {
                break;
            }

            mid = start_index + (end_index - start_index)/2;
            if (nums[mid] < target) {
                start_index = mid + 1;
            } else if (nums[mid] > target) {
                end_index = mid - 1;
            } else {
                if (nums[start_index] < target) {
                    start_index++;
                }

                if (nums[end_index] > target) {
                    end_index--;
                }
            }
        }

        if (nums[start_index] == target && nums[end_index] == target) {
            result = {start_index, end_index};
        }

        return result;
    }
};

TEST_CASE("SearchRange") {
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> answer = {3,4};
    auto res = Solution().searchRange(nums, 8);
    REQUIRE( res == answer);

    nums = {7,7,7,8,8,10};
    answer = {0, 2};
    res = Solution().searchRange(nums, 7);
    REQUIRE( res == answer);

    nums = {7,7,7,7,8,10};
    answer = {0, 3};
    res = Solution().searchRange(nums, 7);
    REQUIRE( res == answer);

    nums = {5,7,7,8,8,10};
    answer = {-1, -1};
    res = Solution().searchRange(nums, 6);
    REQUIRE( res == answer);
}

