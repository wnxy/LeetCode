/**
 * @file 60.offer60.cpp
 * @author your name (you@domain.com)
 * @brief n个骰子的点数
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    void print(vector<int>& nums)
    {
        for(int n: nums)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    // 计算骰子点数和为target的所有组合数
    int sum = 0;
    void dfs(vector<int>& nums, vector<int>& track, int n, int target)
    {
        if(target == 0 && track.size() == n)
        {
            ++sum;
            print(track);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(target - nums[i] < 0 || track.size() >= n)
            {
                return;
            }
            track.emplace_back(nums[i]);
            dfs(nums, track, n, target - nums[i]);
            track.pop_back();
        }
    }

    vector<double> dicesProbability(int n) {
        int min_sum = n;          // 骰子的最小点数和
        int max_sum = n * 6;      // 骰子的最大点数和
        double base_p = 1.0 / 6.0;
        double p = pow(base_p, n);   // 骰子最小点数和出现的概率
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        vector<double> res(max_sum - min_sum + 1);
        vector<int> track;
        int point_sum = min_sum;
        for(int i = 0; i < res.size(); ++i)
        {
            sum = 0;
            dfs(nums, track, n, point_sum++);
            res[i] = p * sum;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,2,3,4,5,6};
    vector<int> track;
    int n = 3;  // 骰子的数量
    //vector<double> res = solution.dicesProbability(n);
    solution.dfs(nums, track, n, 6);
    cout << solution.sum << endl;
    return 0;
}