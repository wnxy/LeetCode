/**
 * @file 474.ones_and_zeroes.cpp
 * @author your name (you@domain.com)
 * @brief 一和零
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, pair<int, int>> dic;
    // 0-1 背包问题
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        for(int i = 0; i < len; ++i)
        {
            int zero_cnt = 0;
            for(auto c: strs[i])
            {
                if(c == '0')
                {
                    ++zero_cnt;
                }
            }
            dic[strs[i]] = make_pair(zero_cnt, strs[i].size() - zero_cnt);
        }
        vector<int> dp(len + 1, 0);
        for(int i = 1; i <= len; ++i)
        {
            int idx = i - 1;
            for(int j = m; j >= 0; --j)
            {
                for(int k = n; k >= 0; --k)
                {
                    if(j >= dic[strs[idx]].first && k >= dic[strs[idx]].second)
                    {
                        dp[i] = max(dp[i], dp[i - 1] + 1);
                    }
                }
            }
        }
        return dp[len];
    }
};

int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    Solution solution;
    cout << solution.findMaxForm(strs, m, n) << endl;
    return 0;
}