/**
 * @file leetcode_weekly_contest_294.cpp
 * @author your name (you@domain.com)
 * @brief leetcode第294场周赛
 * @version 0.1
 * @date 2022-05-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// 折线图 折线段数目
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& lhs, vector<int>& rhs)
    {
        return lhs[0] < rhs[0];
    }
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        int res = 1;
        double k = 0.0;
        int n = stockPrices.size();
        sort(stockPrices.begin(), stockPrices.end(), compare);
        if(n == 1) return 0;
        if(n == 2) return 1;
        k = (double)(stockPrices[1][1] - stockPrices[0][1]) / (double)(stockPrices[1][0] - stockPrices[0][0]);
        for(int i = 1; i < n; ++i)
        {
            double tmp_k = (double)(stockPrices[i][1] - stockPrices[i - 1][1]) / (double)(stockPrices[i][0] - stockPrices[i - 1][0]);
            if(k != tmp_k)
            {
                k = tmp_k;
                ++res;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> stockPrices = {
        {1,1},
        {500000000,499999999},
        {1000000000,999999998}
    };
    Solution solution;
    cout << solution.minimumLines(stockPrices) << endl;
    return 0;
}