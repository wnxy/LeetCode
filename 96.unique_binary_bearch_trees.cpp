/**
 * @file 96.unique_binary_bearch_trees.cpp
 * @author your name (you@domain.com)
 * @brief 不同的二叉搜索树数量
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
            cout << dp[i] << endl;
        }
        return dp[n];
    }
};

int main()
{
    Solution solution;
    int n = 3;
    cout << solution.numTrees(n) << endl;
    return 0;
}