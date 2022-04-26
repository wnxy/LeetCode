/**
 * @file leetcode290.cpp
 * @author your name (you@domain.com)
 * @brief Leetcode周赛第290场
 * @version 0.1
 * @date 2022-04-24
 *
 * @copyright Copyright (c) 2022
 *
 */
// 周赛第一题，求交集
/*
input:
[[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
output:
[3,4]
*/
// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int s[1001];
//     vector<int> intersection(vector<vector<int>>& nums) {
//         memset(s, 0, sizeof(s));
//         for(int i = 0; i < nums.size(); ++i)
//         {
//             for(int n: nums[i])
//             {
//                 ++s[n];
//             }
//         }
//         vector<int> res;
//         for(int i = 1; i < 1001; ++i)
//         {
//             if(s[i] == nums.size())
//             {
//                 res.emplace_back(i);
//             }
//         }
//         return res;
//     }
// };

// int main()
// {

//     return 0;
// }

// 周赛第二题，求解落在圆内的点的总数
/*
input:
circles = [[2,2,2],[3,4,1]]
output:
16
*/
// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     int count[205][205];
//     int countLatticePoints(vector<vector<int>>& circles) {
//         memset(count, 0, sizeof(count));
//         int len = circles.size();
//         for(int i = 0; i < len; ++i)
//         {
//             int x = circles[i][0];
//             int y = circles[i][1];
//             int r = circles[i][2];
//             for(int m = x - r; m <= x + r; ++m)
//             {
//                 for(int n = y - r; n <= y + r; ++n)
//                 {
//                     if((m - x) * (m - x) + (n - y) * (n - y) <= r * r)
//                     {
//                         count[m][n] = 1;
//                     }
//                 }
//             }
//         }
//         int res = 0;
//         for(int i = 0; i < 205; ++i)
//         {
//             for(int j = 0; j < 205; ++j)
//             {
//                 res += count[i][j];
//             }
//         }
//         return res;
//     }
// };

// int main()
// {
//     Solution solution;
//     vector<vector<int>> circles = {{2,2,1}};
//     cout << solution.countLatticePoints(circles) << endl;
//     return 0;
// }

// 周赛第三题，统计包含每个点的矩形数目
/*
input:
rectangles = [[1,2],[2,3],[2,5]], points = [[2,1],[1,4]]
rectangles = [[1,1],[2,2],[3,3]], points = [[1,3],[1,1]]
output:
[2,1]
[1,3]
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        unordered_map<int, vector<int>> dic; // key为高度，value为宽度列表
        for (auto rectangle : rectangles)
        {
            int l = rectangle[0];
            int h = rectangle[1];
            dic[h].push_back(l);
        }
        for (auto it = dic.begin(); it != dic.end(); ++it)
        {
            sort(it->second.begin(), it->second.end());
        }
        vector<int> res;
        for (auto point : points)
        {
            int x = point[0];
            int y = point[1];
            int count = 0;
            for (int h = 1; h < 101; ++h)
            {
                // if (h < y)
                //     break;
                if(y <= h)
                {
                    if (dic.count(h) == 0)
                    continue;
                    auto it = lower_bound(dic[h].begin(), dic[h].end(), x);
                    count += dic[h].end() - it;
                }
                
            }
            res.emplace_back(count);
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> rectangles = {{1, 2}, {2, 3}, {2, 5}};
    vector<vector<int>> points = {{2, 1}, {1, 4}};
    vector<int> res = solution.countRectangles(rectangles, points);
    for(int n: res)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// struct point
// {
//     int x;
//     int y;
//     // bool operator ==(const point& p)
//     // {
//     //     return x == p.x && y == p.y;
//     // }
// };

// class Solution {
// public:
//     bool isRange(vector<int>& circle, point& p)
//     {
//         double r = (double)circle[2];
//         point init = {circle[0], circle[1]};
//         int w = abs(p.x - init.x);
//         int h = abs(p.y - init.y);
//         double dis = sqrt(w * w + h * h);
//         return dis <= r;
//     }

//     int countLatticePoints(vector<vector<int>>& circles) {
//         unordered_set<point> dic;
//         //vector<point> dic;
//         int len = circles.size();
//         for(int k = 0; k < len; ++k)
//         {
//             int x_min = circles[k][0] - circles[k][2];
//             int x_max = circles[k][0] + circles[k][2];
//             int y_min = circles[k][1] - circles[k][2];
//             int y_max = circles[k][1] + circles[k][2];
//             for(int i = x_min; i <= x_max; ++i)
//             {
//                 for(int j = y_min; j <= y_max; ++j)
//                 {
//                     point p = {i, j};
//                     if(isRange(circles[k], p))
//                     {
//                         // if(find(dic.begin(), dic.end(), p) != dic.end())
//                         // {
//                         //     continue;
//                         // }
//                         dic.insert(p);
//                     }
//                 }
//             }
//             // // 向右遍历
//             // for(int j = circles[i][0]; j <= circles[i][0] + circles[i][2]; ++j)
//             // {
//             //     point p = {j, circles[i][1]};
//             //     if(find(dic.begin(), dic.end(), p) != dic.end())
//             //     {
//             //         continue;
//             //     }
//             //     dic.emplace_back(p);
//             // }
//             // // 向左遍历
//             // for(int j = circles[i][0]; j >= (circles[i][0] - circles[i][2]); --j)
//             // {
//             //     point p = {j, circles[i][1]};
//             //     if(find(dic.begin(), dic.end(), p) == dic.end())
//             //     {
//             //         continue;
//             //     }
//             //     dic.emplace_back(p);
//             //     //dic.emplace_back({j, circles[i][1]});
//             // }
//             // // 向上遍历
//             // for(int j = circles[i][1]; j <= circles[i][1] + circles[i][2]; ++j)
//             // {
//             //     point p = {circles[i][0], j};
//             //     if(find(dic.begin(), dic.end(), p) == dic.end())
//             //     {
//             //         continue;
//             //     }
//             //     dic.emplace_back(p);
//             //     //dic.emplace_back({circles[i][0], j});
//             // }
//             // // 向下遍历
//             // for(int j = circles[i][1]; j >= (circles[i][1] - circles[i][2]); --j)
//             // {
//             //     point p = {circles[i][0], j};
//             //     if(find(dic.begin(), dic.end(), p) == dic.end())
//             //     {
//             //         continue;
//             //     }
//             //     dic.emplace_back(p);
//             //     //dic.emplace_back({circles[i][0], j});
//             // }
//         }
//         return dic.size();
//     }
// };

// int main()
// {
//     vector<vector<int>> circles = {{2,2,1}};
//     Solution solution;
//     cout << solution.countLatticePoints(circles) << endl;
//     return 0;
// }

// 第四题

// class Solution {
// public:
//     static bool compare(const vector<int>& v1, const vector<int>& v2)
//     {
//         if(v1[0] != v2[0])
//         {
//             return v1[0] < v2[0];
//         }
//         return v1[1] < v2[1];
//     }

//     vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
//         int n = persons.size();
//         vector<int> res(n);
//         sort(flowers.begin(), flowers.end(), compare);
//         for(int i = 0; i < n; ++i)
//         {
//             int count = 0;
//             for(auto flower: flowers)
//             {
//                 if(persons[i] >= flower[0])
//                 {
//                     if(persons[i] <= flower[1])
//                     {
//                         ++count;
//                     }
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             res[i] = count;
//         }
//         return res;
//     }
// };