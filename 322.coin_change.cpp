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
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount + 1, amount);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(int k : coins)
            {
                if(k <= i)
                {
                    dp[i] = min(dp[i], dp[i - k] + 1);
                }
            }
        }
        for(int n : dp)
        {
            cout << n << " ";
        }
        return dp[amount];
    }
};

int main()
{
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 6;
    int res = solution.coinChange(coins, amount);
    return 0;
}