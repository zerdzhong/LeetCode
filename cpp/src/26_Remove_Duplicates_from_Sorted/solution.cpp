//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) { return static_cast<int>(nums.size()); }

        int last_num = 0;

        for (auto iter = nums.begin(); iter != nums.end(); ) {
            last_num = *iter;
            auto duplicate_end_iter = iter;
            while (*duplicate_end_iter == last_num &&
            duplicate_end_iter != nums.end()) {
                duplicate_end_iter ++;
            }

            if (duplicate_end_iter - iter > 1) {
                iter = nums.erase(iter + 1, duplicate_end_iter);
            } else {
                iter ++;
            }
        }

        return static_cast<int>(nums.size());
    }
};

TEST_CASE("Remove Duplicates from sorted array", "[Basic]") {
    vector<int> nums = {1, 2, 3};
    auto remove_count = Solution().removeDuplicates(nums);

    vector<int> expect_res = {1, 2, 3};
    REQUIRE(nums == expect_res);
    REQUIRE(remove_count == 3);

    nums = {0,0,1,1,1,2,2,3,3,4};
    remove_count = Solution().removeDuplicates(nums);
    expect_res = {0, 1, 2, 3, 4};
    REQUIRE(nums == expect_res);
    REQUIRE(remove_count == 5);
}

