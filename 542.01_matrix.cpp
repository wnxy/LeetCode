/**
 * @file 542.01_matrix.cpp
 * @author your name (you@domain.com)
 * @brief 0-1矩阵
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int direct[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    int m, n;

    int bfs(vector<vector<int>> mat, queue<pair<int, int>>& q)
    {
        int res = 0;
        while(!q.empty())
        {
            ++res;
            for(int k = q.size(); k > 0; --k)
            {
                auto [x, y] = q.front();
                mat[x][y] = 2;
                q.pop();
                for(int i = 0; i < 4; ++i)
                {
                    int dx = x + direct[i][0];
                    int dy = y + direct[i][1];
                    if(dx < 0 || dx >= m || dy < 0 || dy >= n || mat[dx][dy] == 2)
                    {
                        continue;
                    }
                    if(mat[dx][dy] == 0)
                    {
                        return res;
                    }
                    q.push(make_pair(dx, dy));
                }
            } 
        }
        return res;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(mat[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    res[i][j] = bfs(mat, q);
                }
            }
        }
        return res;
    }
};

class Solution1 {
public:
    int direct[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    struct Node
    {
        int x; 
        int y;
        int dis;
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        queue<Node> q;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(mat[i][j] == 0)
                {
                    mat[i][j] = 2;
                    q.push({i, j, 0});
                }
            }
        }
        while(!q.empty())
        {
            for(int i = q.size(); i > 0; --i)
            {
                auto node = q.front();
                q.pop();
                if(mat[node.x][node.y] == 0)
                {
                    res[node.x][node.y] = ::min(res[node.x][node.y], node.dis);
                }
                for(int j = 0; j < 4; ++j)
                {
                    int dx = node.x + direct[j][0];
                    int dy = node.y + direct[j][1];
                    if(dx < 0 || dx >= m || dy < 0 || dy >= n || mat[dx][dy] == 2)
                    {
                        continue;
                    }
                    mat[dx][dy] = 2;
                    q.push({dx, dy, node.dis + 1});
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    Solution1 solution;
    vector<vector<int>> res = solution.updateMatrix(mat);
    return 0;
}