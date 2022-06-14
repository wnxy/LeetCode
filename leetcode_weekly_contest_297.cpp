/**
 * @file leetcode_weekly_contest_297.cpp
 * @author your name (you@domain.com)
 * @brief LeetCode 第297场周赛
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// 周赛第二题
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
//         int res = INT_MAX;
//         // m行，n列
//         int m = grid.size(), n = grid[0].size();
//         // vector<int> dp(grid[0].begin(), grid[0].end());
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for(int i = 0; i < n; ++i)
//         {
//             dp[0][i] = grid[0][i];
//         }
//         for(int i = 1; i < m; ++i)
//         {
            
//             for(int j = 0; j < n; ++j)
//             {
//                 int tt = INT_MAX;
//                 for(int k = 0; k < n; ++k)
//                 {
//                     tt = min(tt, dp[i - 1][k] + grid[i][j] + moveCost[grid[i - 1][k]][j]);
//                 }
//                 dp[i][j] = tt;
//             }
//         }
//         for(auto num: dp[m - 1])
//         {
//             res = min(res, num);
//         }
//         return res;
//     }
// };

// int main()
// {
//     vector<vector<int>> grid = {
//         {5,3},
//         {4,0},
//         {2,1}
//     };
//     vector<vector<int>> moveCost = {
//     {9,8},{1,5},{10,12},{18,6},{2,4},{14,3}
//     };
//     Solution solution;
//     cout << solution.minPathCost(grid, moveCost) << endl;
// }


// 周赛 第三题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        if(n == k)
        {
            return *min_element(cookies.begin(), cookies.end());
        }
        int sum = 0;
        for(int cookie: cookies)
        {
            sum += cookie;
        }
        if()
        return 0;
    }
};

int main()
{

    return 0;
}