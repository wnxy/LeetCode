/**
 * @file 15.3sum.cpp
 * @author your name (you@domain.com)
 * @brief 三数之和为0
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void backTrack(vector<int>& nums, vector<int>& track, int target, int begin)
    {
        if(target == 0 && track.size() == 3)
        {
            res.emplace_back(track);
            return;
        }
        for(decltype(nums.size()) i = begin; i < nums.size(); ++i)
        {
            if((track.size() == 3 && target != 0)) 
                return;
            if(i > begin && nums[i] == nums[i - 1])
                continue;
            track.emplace_back(nums[i]);
            backTrack(nums, track, target - nums[i], i + 1);
            track.pop_back();
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return res;
        vector<int> track;
        sort(nums.begin(), nums.end());
        backTrack(nums, track, 0, 0);
        return res;
    }
};

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int first = 0; first < len; ++first)
        {
            if(nums[first] > 0)
            {
                break;
            }
            if(first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int target = -nums[first];
            //左右双指针寻找b,c两个数
            int right = len - 1;
            for(int left = first + 1; left < right; ++left)
            {
                if(left > first + 1 && nums[left] == nums[left - 1])
                {
                    continue;
                }
                while(right > left && nums[left] + nums[right] > target)
                {
                    --right;
                }
                if(left == right) break;
                if(nums[left] + nums[right] == target)
                {
                    res.push_back({nums[first], nums[left], nums[right]});
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution1 solution;
    vector<int> nums = {0,1,1};
    vector<vector<int>> res = solution.threeSum(nums);
    return 0;
}