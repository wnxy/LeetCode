/**
 * @file 416.partition_equal_subset_sum.cpp
 * @author your name (you@domain.com)
 * @brief 分割等和子集
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 如果sum是奇数，直接返回
        if(sum & 1)
        {
            return false;
        }
        int maxNum = *max_element(nums.begin(), nums.end());
        int target = sum >> 1;
        // 如果最大值大于元素总和的一半，直接返回
        if(maxNum > target)
        {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for(int i = 0; i < n; ++i)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; ++i)
        {
            int num = nums[i];
            for(int j = 0; j <= target; ++j)
            {
                if(j >= num)
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

int main()
{
    vector<int> nums = {2,2,1,1};
    Solution solution;
    cout << solution.canPartition(nums) << endl;
    return 0;
}