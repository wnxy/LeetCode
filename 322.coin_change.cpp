/**
 * @file 322.coin_change.cpp
 * @author your name (you@domain.com)
 * @brief 零钱兑换
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 完全背包问题
    // dp[i][j]表示前i个元素组成金额为J需要的硬币个数
    /**
     * @brief 完全背包问题，空间未优化版
     * 
     * @param coins 
     * @param amount 
     * @return int 
     */
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
        for(int i = 0; i < n; ++i)
        {
            dp[i][0] = 0;
        }
        for(int i = 1; i <= amount; ++i)
        {
            if(i % coins[0] == 0)
            {
                dp[0][i] = i / coins[0];
            }
        }
        for(int i = 1; i < n; ++i)
        {
            for(int j = 1; j <= amount; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                for(int k = 1; k <= j / coins[i]; ++k)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - k * coins[i]] + k);
                }
            }
        }
        return dp[n - 1][amount] == INT_MAX? -1: dp[n - 1][amount];
    }

    // 完全背包问题
    // dp[j]表示前i个元素组成金额为J需要的硬币个数
    /**
     * @brief 完全背包问题，空间优化版
     * 
     * @param coins 
     * @param amount 
     * @return int 
     */
    int coinChange1(vector<int>& coins, int amount)
    {
        if(amount == 0)
        {
            return false;
        }
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = amount; j >= 1; --j)
            {
                for(int k = 0; k <= j / coins[i]; ++k)
                {
                    dp[j] = min(dp[j], dp[j - k * coins[i]] + k);
                }
            }
        }
        return dp[amount] == amount + 1? -1: dp[amount];
    }
    
    // 完全背包问题
    // dp[j]表示前i个元素组成金额为J需要的硬币个数
    /**
     * @brief 完全背包问题，另一种思路，空间优化版
     * 
     * @param coins 
     * @param amount 
     * @return int 
     */
    int coinChange2(vector<int>& coins, int amount)
    {
        if(amount == 0)
        {
            return false;
        }
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = coins[i]; j <= amount; ++j)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == amount + 1? -1: dp[amount];
    }
};

int main()
{
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int res = solution.coinChange2(coins, amount);
    cout << res << endl;
    return 0;
}