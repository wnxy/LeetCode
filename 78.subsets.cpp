/**
 * @file 78.subsets.cpp
 * @author your name (you@domain.com)
 * @brief 子集问题
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int> track;
        dfs(nums, track, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& track, int start)
    {
        if(start < 0 || start >= nums.size()) 
            return;
        res.emplace_back(track);
        for(int i = start; i < nums.size(); ++i)
        {
            track.emplace_back(nums[i]);
            dfs(nums, track, i + 1);
            track.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = solution.subsets(nums);
    return 0;
}