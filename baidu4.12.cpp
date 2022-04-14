/**
 * @file baidu4.12.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// 百度第一题
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     string step = "";
//     cin >> step;
//     int x = 0, y = 0;
//     for(const char& c: step)
//     {
//         if(c == 'R')
//         {
//             ++x;
//         }
//         else if(c == 'L')
//         {
//             --x;
//         }
//         else if(c == 'U')
//         {
//             ++y;
//         }
//         else if(c == 'D')
//         {
//             --y;
//         }
//     }
//     cout << "(" << x << "," << y << ")" << endl;
//     return 0;
// }


// 百度第二题

// 3 5 3
// #....
// ####.
// FS...
// 1 1
// 2 3
// 2 2

// 17
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int s_r, s_c, f_r, f_c;
// int n, m, k, start_r, start_c, end_r, end_c;

// struct point
// {
//     int x;
//     int y;
// };

// vector<vector<int>> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// void dfs(vector<vector<char>>& matrix, vector<vector<int>>& vis, point& start, point& end, int& path, int i, int j)
// {
//     if(i <= 0 || i > n || j <= 0 || j > m || vis[i][j] == 1 || matrix[i][j] == '#')
//     {
//         return;
//     }
//     if(end.x == i && end.y == j)
//     {
//         return;
//     }
//     ++path;
//     vis[i][j] = 1;
//     dfs(matrix, vis, start, end, path, i + 1, j);
//     dfs(matrix, vis, start, end, path, i - 1, j);
//     dfs(matrix, vis, start, end, path, i, j + 1);
//     dfs(matrix, vis, start, end, path, i, j - 1);
//     vis[i][j] = 0;
// }

// int main()
// {
//     cin >> n >> m >> k;
//     vector<vector<char>> matrix(n + 1, vector<char>(m + 1));
//     vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
//     for(int i = 1; i <= n; ++i)
//     {
//         for(int j = 1; j <= m; ++j)
//         {
//             cin >> matrix[i][j];
//             if(matrix[i][j] == 'S')
//             {
//                 start_r = i;
//                 start_c = j;
//             }
//             else if(matrix[i][j] == 'F')
//             {
//                 end_r = i;
//                 end_c = j;
//             }
//         }
//     }
//     vector<vector<int>> block(k, vector<int>(2));
//     for(int i = 0; i < k; ++i)
//     {
//         cin >> block[i][0] >> block[i][1];
//     }
//     int res = 0;
//     // 遍历每一个石头
//     s_r = start_r;
//     s_c = start_c;
//     for(int j = 0; j < k; ++j)
//     {
//         point start;
//         if(j == 0)
//         {
//            start.x = start_c;
//            start.y = start_r;
//         }
//         /*else 
//         {
//             start.x
//         }*/
//         int min_path = n + m;
//         for(int i = 0; i < 4; ++i)
//         {
//             int path = 0;
//             point end;
//             end.x = block[j][0] + direct[i][0];
//             end.y = block[j][1] + direct[i][1];
//             if(matrix[end.x][end.y] != '#')
//             {
//                 dfs(matrix, vis, start, end, path, start_c, start_r);
//                 min_path = min(min_path, path);
//             }
//         }
//         res += min_path;
//     }
//     cout << res << endl;
//     return 0;
// }


// 百度第三题

// 4 
// 3 4 1 2 
// 3 2 4 1

// 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    for(int i = 0; i < N; ++i)
    {
        cin >> B[i];
    }
    int res = 0, sum = 0;
    vector<int> tmp1 = A;
    vector<int> tmp2 = B;
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());
    for(int n: tmp1)
    {
        cout << n << " ";
    }
    for(int n: tmp2)
    {
        cout << n << " ";
    }
    // 求最大差异和
    for(int i = 0; i < N; ++i)
    {
        sum += abs(tmp1[i] - tmp2[N - 1 - i]);
    }
    //for()
    cout << sum << endl;
    return 0;
}