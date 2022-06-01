/**
 * @file 47.permutations_II.cpp
 * @author your name (you@domain.com)
 * @brief 全排列 II
 * @version 0.1
 * @date 2022-03-08
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

    void backTrack(vector<int>& nums, vector<int>& track, vector<int>& used, int begin)
    {
        if(track.size() == nums.size())
        {
            res.emplace_back(track);
            return;
        }
        for(decltype(nums.size()) i = begin; i < nums.size(); ++i)
        {
            if(used[i] == 1) 
                continue;
            if(i > begin && nums[i] == nums[i - 1] && !used[i - 1])
            {
                return;
            }
            track.emplace_back(nums[i]);
            used[i] = 1;
            backTrack(nums, track, used, 0);
            track.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> track;
        vector<int> used(nums.size(), 0);
        backTrack(nums, track, used, 0);
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,1,2};
    vector<vector<int>> res = solution.permuteUnique(nums);
    return 0;
}