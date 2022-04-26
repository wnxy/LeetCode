/**
 * @file 1262.greatest_sum_divisible_by_three.cpp
 * @author your name (you@domain.com)
 * @brief 可被3整除的最大和
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // dp[i][0]表示nums[0.....i]中模3余0的最大和
    // dp[i][1]表示nums[0.....i]中模3余1的最大和
    // dp[i][2]表示nums[0.....i]中模3余2的最大和
    int maxSumDivThree(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(3, 0));
        dp[0][0] = 0; dp[0][1] = INT_MIN; dp[0][2] = INT_MIN;

        for(int i = 1; i <= len; ++i)
        {
            if(nums[i - 1] % 3 == 0)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][2] + nums[i - 1]);
            }
            else if(nums[i - 1] % 3 == 1)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + nums[i - 1]);
            }
            else if(nums[i - 1] % 3 == 2)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + nums[i - 1]);
            }
        }
        return dp[len][0];
    }
};

int main()
{
    vector<int> nums = {3, 6, 5, 1, 8};
    Solution solution;
    cout << solution.maxSumDivThree(nums) << endl;
    return 0;
}