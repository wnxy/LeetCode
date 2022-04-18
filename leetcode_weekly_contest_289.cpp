/**
 * @file leetcode289.cpp
 * @author your name (you@domain.com)
 * @brief leetcode 289场周赛
 * @version 0.1
 * @date 2022-04-17
 *
 * @copyright Copyright (c) 2022
 *
 */

// 周赛第一题
// #include <iostream>
// #include <string>
// using namespace std;

// class Solution {
// public:
//     string digitSum(string s, int k) {
//         if(s.empty()) return "";
//         string res = s;
//         while(res.length() > k)
//         {
//             res = helper(res, k);
//             cout << res << endl;
//         }
//         return res;
//     }

//     string helper(string& s, int k)
//     {
//         string res = "";
//         int tmp = 0, count = k;
//         for(int i = 0; i < s.length(); ++i)
//         {
//             if(count <= 0)
//             {
//                 res += to_string(tmp);
//                 tmp = 0;
//                 count = k;
//             }
//             tmp += s[i] - '0';
//             --count;
//         }
//         res += to_string(tmp);
//         return res;
//     }
// };

// int main()
// {
//     string s = "00000000";
//     int k = 3;
//     Solution solution;
//     cout << solution.digitSum(s, k) << endl;
//     return 0;
// }

// 周赛第二题
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        if(tasks.empty()) return -1;
        sort(tasks.begin(), tasks.end());
        int level = tasks[0];
        int count = 0;    // 完成任务需要的轮数
        int tmp = 0;
        for(int i = 0; i < tasks.size(); ++i)
        {
            if(tasks[i] != level)
            {
                if(tmp < 2) return -1;
                count += tmp / 3;
                if(tmp % 3 != 0)
                    ++count;
                level = tasks[i];
                tmp = 0;
            }
             ++tmp;
        }
        if(tmp < 2) return -1;
        count += tmp / 3;
        if(tmp % 3 != 0)
            ++count;
        return count;
    }
};

class Solution1 {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> dic;
        for(const int& t: tasks)
        {
            ++dic[t];
        }
        int res = 0;
        for(auto it: dic)
        {
            res += ceil(static_cast<double>(it.second) / 3);
        }
        return res;
    }
};

int main()
{
    Solution1 solution;
    //cout << ceil(3);
    //cout << floor(2.5);
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    cout << solution.minimumRounds(tasks) << endl;
    return 0;
}

// 周赛第三题
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution
// {
// public:
//     int m, n;
//     int maxTrailingZeros(vector<vector<int>> &grid)
//     {
//         if (grid.empty())
//             return 0;
//         m = grid.size();
//         n = grid[0].size();
//         vector<vector<int>> visited(m, vector<int>(n));
//         int res = 0;
//         for (int i = 0; i < m; ++i)
//         {
//             for (int j = 0; j < n; ++j)
//             {
//                 long long multi = 1;
//                 dfs(grid, visited, i, j, 0, 1, 0, multi);
//                 res = max(res, calc(multi));
//                 dfs(grid, visited, i, j, 0, 0, 1, multi);
//                 res = max(res, calc(multi));
//             }
//         }
//         return res;
//     }

//     void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j, int count,
//              int level, int his, long long &multi)
//     {
//         if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 1 || count > 1)
//         {
//             return;
//         }
//         if (calc(multi) > calc(multi * grid[i][j]))
//         {
//             return;
//         }
//         visited[i][j] = 1;
//         multi *= grid[i][j];
//         if (level == 1)
//         {
//             dfs(grid, visited, i, j + 1, count, 1, 0, multi);
//             dfs(grid, visited, i, j - 1, count, 1, 0, multi);

//             dfs(grid, visited, i + 1, j, count + 1, 0, 1, multi);
//             dfs(grid, visited, i - 1, j, count + 1, 0, 1, multi);
//         }
//         else if (his == 1)
//         {
//             dfs(grid, visited, i + 1, j, count, 0, 1, multi);
//             dfs(grid, visited, i - 1, j, count, 0, 1, multi);

//             dfs(grid, visited, i, j + 1, count + 1, 1, 0, multi);
//             dfs(grid, visited, i, j - 1, count + 1, 1, 0, multi);
//         }
//         visited[i][j] = 0;
//     }

//     int calc(long long num)
//     {
//         int res = 0;
//         while (num % 10 == 0)
//         {
//             ++res;
//             num /= 10;
//         }
//         return res;
//     }
// };

// int main()
// {
//     Solution solution;
//     vector<vector<int>> grid = {
//         {23, 17, 15, 3, 20},
//         {8, 1, 20, 27, 11},
//         {9, 4, 6, 2, 21},
//         {40, 9, 1, 10, 6},
//         {22, 7, 4, 5, 3}
//     };
//     cout << solution.maxTrailingZeros(grid) << endl;
//     return 0;
// }