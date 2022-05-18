/**
 * @file 13.offer13.cpp
 * @author your name (you@domain.com)
 * @brief 机器人的运动范围
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
    // 获取整数的位数之和
    int getBit(int n)
    {
        int res = 0;
        while(n)
        {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int movingCount(int m, int n, int k) {
        if(k == 0) return 1;
        int direct[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        int res = 1;
        vector<vector<int>> isVisted(m, vector<int>(n, 0));
        queue<pair<int, int>> q;   // BFS辅助队列，pair表示横纵坐标
        q.push(make_pair(0, 0));
        isVisted[0][0] = 1;
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            //isVisted[pos.first][pos.second] = 1;
            //++res;
            for(int i = 0; i < 4; ++i)
            {
                int dx = x + direct[i][0];
                int dy = y + direct[i][1];
                if(dx < 0 || dx >= m || dy < 0 || dy >= n || isVisted[dx][dy] || getBit(dx) + getBit(dy) > k)
                {
                    continue;
                }
                isVisted[dx][dy] = 1;
                q.push({dx, dy});
                ++res;
            }
        }
        return res;
    }
};

int main()
{
    int m = 3, n = 2, k = 17;
    Solution solution;
    cout << solution.movingCount(m, n, k) << endl;
    return 0;
}