// 网易笔试第一题
/*
打印字母O
input:
1
output:
.**.
*..*
*..*
.**.

2

..****..
.******.
**....**
**....**
**....**
**....**
.******.
..****..

*/
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     // w表示一行内的字符数，h表示行数
//     int w = 4 * n, h = 4 * n;
//     int tmp = n * 2;
//     for(int i = 0; i < n; ++i)
//     {
//         for(int j = 0; j < n - i; ++j)
//         {
//             cout << ".";
//         }
//         for(int j = 0; j < tmp; ++j)
//         {
//             cout << "*";
//         }
//         for(int j = 0; j < n - i; ++j)
//         {
//             cout << ".";
//         }
//         cout << endl;
//         tmp += 2;
//     }
//     for(int i = 0; i < 2 * n; ++i)
//     {
//         for(int j = 0; j < n; ++j)
//         {
//             cout << "*";
//         }
//         for(int j = 0; j < 2 * n; ++j)
//         {
//             cout << ".";
//         }
//         for(int j = 0; j < n; ++j)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
//     tmp -= 2;
//     for(int i = n - 1; i >= 0; --i)
//     {
//         for(int j = 0; j < n - i; ++j)
//         {
//             cout << ".";
//         }
//         for(int j = 0; j < tmp; ++j)
//         {
//             cout << "*";
//         }
//         for(int j = 0; j < n - i; ++j)
//         {
//             cout << ".";
//         }
//         cout << endl;
//         tmp -= 2;
//     }
//     return 0;
// }



// 网易校招第二题
/*
input:
4 6 15
output:
1 3 6 5
*/
// #include <iostream>
// #include <vector>
// using namespace std;

// // 长度为n的数组，最大值不超过k，数组和为x
// int n, k, x;
// vector<int> res;
// void helper(vector<int>& nums, vector<int>&track, int i, int target)
// {
//     if(i < 0 || i >= k) return;
//     if(target == 0)
//     {
//         if(track.size() == n)
//         {
//             res = track;
//             return;
//         }
//         else
//         {
//             return;
//         }
//     }
//     if(target < 0) return;
//     for(int j = i; j < k; ++j)
//     {
//         track.emplace_back(nums[j]);
//         helper(nums, track, j + 1, target - nums[j]);
//         track.pop_back();
//     }
// }

// int main()
// {
//     cin >> n >> k >> x;
//     vector<int> nums(k);
//     for(int i = 0; i < k; ++i)
//     {
//         nums[i] = i + 1;
//     }
//     vector<int> track;
//     helper(nums, track, 0, x);
//     if(res.empty())
//     {
//         cout << -1 << endl;
//     }
//     else
//     {
//         for(int n: res)
//         {
//             cout << n << " ";
//         }
//     }
//     return 0;
// }


// 网易笔试第三题
/*
input
3 3
5 8 25
1 2
2 3
1 3
output
2
*/
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// /**
//  * @brief 计算两个顶点权值的最大价值
//  * 
//  * @param a1 
//  * @param a2 
//  * @return int 
//  */
// int calc(int a1, int a2)
// {
//     long multi = a1 * a2;
//     int res = 0;
//     while(multi % 10 == 0)
//     {
//         ++res;
//         multi /= 10;
//     }
//     return res;
// }

// /**
//  * @brief 判断给点的无向图是不是连通图
//  * 
//  * @param edges 图得邻接表
//  * @param n 图得顶点个数
//  * @return true 
//  * @return false 
//  */
// bool judge(vector<vector<int>>& edges, int n)
// {
//     for(int i = 1; i <= n; ++i)
//     {
//         if(edges[i].empty())
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int helper(vector<vector<int>>& edges, vector<int>& value, int n, int i)
// {
//     int res = 0;
//     vector<vector<int>> tmp = edges;
//     for(int node: tmp[i])
//     {
//         if(judge(edges, n))
//         {
//             res = max(res, calc(value[i], value[node]));
//             edges[i].erase(node);
//         }
//     }
// }

// int main()
// {
//     // n表示节点数，m表示边数
//     int n, m;
//     cin >> n >> m;
//     vector<int> value(n + 1);
//     for(int i = 1; i <= n; ++i)
//     {
//         cin >> value[i];
//     }
//     vector<vector<int>> edges;
//     int u, v;
//     for(int i = 0; i < m; ++i)
//     {
//         cin >> u >> v;
//         edges.push_back({u, v});
//     }
//     int res = 0;
//     for(int i = 0; i < m; ++i)
//     {
//         res = max(res, calc(edges[i][0], edges[i][1]));
//     }
//     cout << res << endl;
//     return 0;
// }


// 网易第四题
/*
input:
3
10 2 5
output:
5
*/
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 计算区间权值
 * 
 * @param nums 
 * @param left 
 * @param right 
 * @return int 
 */
int calc(long long num)
{
    long long multi = num;
    int res = 0;
    while(multi >= 0 && multi % 10 == 0)
    {
        ++res;
        multi /= 10;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    int res = 0;
    long long multi = 1;
    for(int i = 0; i < n; ++i)
    {
        multi *= nums[i];
        for(int j = i; j < n; ++j)
        {
            res += calc(multi);
            multi *= nums[j];
        }
        multi = 1;
    }
    cout << res << endl;
    return 0;
}