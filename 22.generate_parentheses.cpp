/**
 * @file 22.generate_parentheses.cpp
 * @author your name (you@domain.com)
 * @brief 括号生成
 * @version 0.1
 * @date 2022-02-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }

    // left表示当前左括号可用的数目，right表示当前右括号可用的数目
    void dfs(vector<string>& res, string ans, int left, int right)
    {
        if(left == 0 && right == 0)
        {
            res.emplace_back(ans);
            return;
        }
        if(left == right)
        {
            dfs(res, ans + '(', left - 1, right);
        }
        else if(right > left)
        {
            if(left > 0)
            {
                dfs(res, ans + '(', left - 1, right);
            }
            dfs(res, ans + ')', left, right - 1);
        }
    }
};

class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {""};
        if(n == 1) return {"()"};
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};
        for(int i = 2; i <= n; ++i)
        {
            //vector<string> tmp;
            for(int j = 0; j < i; ++j)
            {
                for(string p : dp[j])
                {
                    for(string q : dp[i - 1 - j])
                    {
                        string str = "(" + p + ")" + q;
                        dp[i].emplace_back(str);
                    }
                }
            }
            //dp.push_back(tmp);
        }
        return dp[n];
    }
};

int main()
{
    Solution3 solution;
    vector<string> res = solution.generateParenthesis(2);
    return 0;
}