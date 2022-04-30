/**
 * @file 399.evaluate_division.cpp
 * @author your name (you@domain.com)
 * @brief 除法求值
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
解释：
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>& mp, string& key, string& value, double& sum, unordered_map<string, int>& flag)
    {
        if(key == value) return true;
        for(auto [a1, a2]: mp[key])
        {
            if(flag[a1] == 0)
            {
                flag[a1] = 1;
                sum *= a2;
                if(dfs(mp, a1, value, sum, flag))
                {
                    return true;
                }
                sum /= a2;
                flag[a1] = 0;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        int n = equations.size();
        for(decltype(equations.size()) i = 0; i < n; ++i)
        {
            mp[equations[i][0]].emplace_back(pair(equations[i][1], values[i]));
            mp[equations[i][1]].emplace_back(pair(equations[i][0], 1.0 / values[i]));
        }
        int m = queries.size();
        vector<double> res(m);
        for(decltype(queries.size()) i = 0; i < m; ++i)
        {
            // 哈希表中是否存在键值
            if(mp.count(queries[i][0]) > 0)
            {
                unordered_map<string, int> flag;
                double sum = 1.0;
                res[i] = dfs(mp, queries[i][0], queries[i][1], sum, flag) == true? sum: -1.0;
            }
            else
            {
                res[i] = -1.0;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}