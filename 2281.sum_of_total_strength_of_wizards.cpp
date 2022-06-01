/**
 * @file 2281.sum_of_total_strength_of_wizards.cpp
 * @author your name (you@domain.com)
 * @brief 巫师的总力量和
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    const int MOD = 1e9+7;
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        // 寻找左边小于当前元素的边界
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && strength[stk.top()] >= strength[i])
            {
                stk.pop();
            }
            if(!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        // 寻找右边小于等于当前元素的边界
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && strength[stk.top()] >= strength[i])
            {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        long psum = 0L; // 前缀和
        vector<int> ppsum(n + 2); // 前缀和的前缀和
        for (int i = 1; i <= n; ++i) 
        {
            psum += strength[i - 1];
            ppsum[i + 1] = (ppsum[i] + psum) % MOD; // 注意取模后，下面计算两个 ss 相减，结果可能为负
        }
        long long res = 0;
        for(int i = 0; i < n; ++i)
        {
            long long l = left[i] + 1, r = right[i] - 1;
            long long con = (ppsum[r + 2] - ppsum[i + 1]) * (i - l + 1) - (ppsum[i + 1] - ppsum[l]) * (r - i + 1);
            res = (res + strength[i] * con) % MOD;
        }
        return res % MOD;
    }
};

int main()
{
    vector<int> strength = {1, 3, 1, 2};
    Solution solution;
    cout << solution.totalStrength(strength) << endl;
    return 0;
}