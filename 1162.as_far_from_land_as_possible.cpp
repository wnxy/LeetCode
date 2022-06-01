/**
 * @file 1162.as_far_from_land_as_possible.cpp
 * @author your name (you@domain.com)
 * @brief 地图分析
 * @version 0.1
 * @date 2022-05-11
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

    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    grid[i][j] = 2;
                }
            }
        }
        if(q.empty() || q.size() == n * n)
        {
            return -1;
        }
        int res = 0;
        while(!q.empty())
        {
            for(int i = q.size(); i > 0; --i)
            {
                auto [x, y] = q.front();
                q.pop();
                for(int j = 0; j < 4; ++j)
                {
                    int dx = x + direct[j][0];
                    int dy = y + direct[j][1];
                    if(dx < 0 || dx >= n || dy < 0 || dy >= n || grid[dx][dy] == 2)
                    {
                        continue;
                    }
                    grid[dx][dy] = 2;
                    q.push(make_pair(dx, dy));
                }
            }
            ++res;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };
    Solution solution;
    cout << solution.maxDistance(grid) << endl;
    return 0;
}
