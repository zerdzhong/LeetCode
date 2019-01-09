//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
    https://leetcode.com/problems/combination-sum/
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        if(candidates.size() == 0 || target == 0) {return result; }

        vector<int> list;
        dfs(candidates, target, 0, result, list);

        return result;
    }

    void dfs(vector<int> candidates, 
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
            list.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, result, list);
            list.pop_back();
        }
    }
};

TEST_CASE("CombinationSum") {
    vector<int> candidates = {2,3,6,7};
    auto res = Solution().combinationSum(candidates, 7);
    vector<vector<int>> answer = {{7},{2,2,3}};
    REQUIRE(res == answer);

    candidates = {2,3,5};
    res = Solution().combinationSum(candidates, 4);
    answer = {{2,2,2,2},{2,3,3},{3,5}};
    REQUIRE(res == answer);

}

