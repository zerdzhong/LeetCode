//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
    https://leetcode.com/problems/combination-sum-ii/
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        if(candidates.size() == 0 || target == 0) { return result; }

        sort(candidates.begin(), candidates.end());

        vector<int> list;
        dfs(candidates, target, 0, result, list);

        return result;
    }

    void dfs(const vector<int> &candidates,
                int target, 
                int level, 
                vector<vector<int>>& result, 
                vector<int>& list) 
    {

        if (target < 0 ){
            return;
        }
        if(target == 0) {
            result.push_back(list);
            return;
        }

        for(int i = level; i < candidates.size(); i++) {
            if (i != level && candidates[i] == candidates[i-1] ) {
                continue;
            }
            list.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, result, list);
            list.pop_back();
        }
    }
};

TEST_CASE("CombinationSumII") {
    vector<int> candidates = {10,1,2,7,6,1,5};
    auto res = Solution().combinationSum2(candidates, 8);
    vector<vector<int>> answer = {{1,7},{1,2,5},{2,6},{1,1,6}};
    REQUIRE(res == answer);

    candidates = {2,5,2,1,2};
    res = Solution().combinationSum2(candidates, 5);
    answer = {{1,2,2},{5}};
    REQUIRE(res == answer);

}

