//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int original_count = static_cast<int>(nums.size());
        int remove_count = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            if (*iter == val) {
                remove_count ++;
            } else {
                *(iter - remove_count) = *iter;
            }
        }

        nums.resize(original_count - remove_count);

        return original_count - remove_count;
    }
};

TEST_CASE("Remove Element") {
    vector<int> nums = {3,2,2,3};
    auto new_count = Solution().removeElement(nums, 3);

    vector<int> expect_res = {2, 2};
    REQUIRE(nums == expect_res);
    REQUIRE(new_count == 2);

    nums = {0,1,2,2,3,0,4,2};
    new_count = Solution().removeElement(nums, 2);
    expect_res = {0, 1, 3, 0, 4};
    REQUIRE(nums == expect_res);
    REQUIRE(new_count == 5);
}

