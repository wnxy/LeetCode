/**
 * @file 1449.form_largest_integer_with_digits_that_add_up_to_target.cpp
 * @author your name (you@domain.com)
 * @brief 数位成本和为目标值的最大数字
 * 完全背包问题
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 比较两个字符串的大小
    string max(const string &s1, const string &s2)
    {
        if(s1 == "NON" || s2 == "NON")
        {
            return s1 == "NON"? s2: s1;
        }
        if(s1.size() == s2.size())
        {
            return s1 < s2? s2: s1;
        }
        return s1.size() < s2.size()? s2: s1;
    }

    // 连接两个字符串
    string connect(const string& s1, const string& s2)
    {
        if(s1 == "NON" || s2 == "NON")
        {
            return "NON";
        }
        return s1 + s2;
    }

    // 完全背包问题
    // dp[j]表示前i个元素target限制为j时，所能获得的最大整数
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<string> dp(target + 1, "NON");
        dp[0] = "";
        for(int i = 0; i < n; ++i)
        {
            for(int j = cost[i]; j <= target; ++j)
            {
                dp[j] = max(dp[j], connect(dp[j - cost[i]], to_string(i + 1)));
            }
        }
        return dp[target];
    }
};

int main()
{
    vector<int> cost = {4,3,2,5,6,7,2,5,5};
    int target = 9;
    Solution solution;
    string res = solution.largestNumber(cost, target);
    cout << res << endl;
    return 0;
}