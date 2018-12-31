//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nums_map = map<int, int>();

        for (int index = 0; index < nums.size(); ++index) {
            int need_num = target - nums[index];
            auto need_num_index = nums_map.find(need_num);

            if (need_num_index != nums_map.end()) {
                return {need_num_index->second, index};
            }

            nums_map[nums[index]] = index;
        }
        return {};
    }
};

TEST_CASE("Two Sum", "[Two_Sum]") {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> actual_res = Solution().twoSum(nums, 9);
    vector<int> expect_res = {0, 1};
    REQUIRE(actual_res == expect_res);

    nums = {3,2,4};
    actual_res = Solution().twoSum(nums, 6);
    expect_res = {1, 2};
    REQUIRE(actual_res == expect_res);
}

