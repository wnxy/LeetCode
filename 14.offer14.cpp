/**
 * @file 14.offer14.cpp
 * @author your name (you@domain.com)
 * @brief 剪绳子
 * @version 0.1
 * @date 2022-02-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for(int i = 3; i < n + 1; ++i)
        {
            for(int j = 2; j < i; ++j)
            {
                //long tmp = (j * dp[i - j]) % 1000000007;
                //dp[i] = max(dp[i], max(j * (i - j), (int)tmp));
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                dp[i] = dp[i] % 1000000007;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution solution;
    int n = 120;
    cout << solution.cuttingRope(n) << endl;
    return 0;
}