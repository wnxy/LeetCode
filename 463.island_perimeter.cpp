/**
 * @file 463.island_perimeter.cpp
 * @author your name (you@domain.com)
 * @brief 岛屿的周长
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int res = 0;
    vector<vector<int>> direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        {
            ++res;
            return;
        }
        if(grid[i][j] == 2) return;
        grid[i][j] = 2;
        for(int k = 0; k < 4; ++k)
        {
            int dx = i + direct[k][0];
            int dy = j + direct[k][1];
            dfs(grid, m, n, dx, dy);
        }
        //grid[i][j] = 1;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        bool tag = false;
        for(int i = 0; i < row; ++i)
        {
            if(tag == false)
            {
                for(int j = 0; j < col; ++j)
                {
                    if(grid[i][j] == 1)
                    {
                        dfs(grid, row, col, i, j);
                        tag = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    Solution solution;
    cout << solution.islandPerimeter(grid) << endl;
    return 0;
}
