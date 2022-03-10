/**
 * @file 39.combination_sum.cpp
 * @author your name (you@domain.com)
 * @brief 组合总和
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void print(vector<int>& track)
    {
        cout << "[";
        for(auto it = track.begin(); it != track.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << "]";
    }

    void backTrack(vector<int>& candidates, vector<int>& track, int target, int begin)
    {
        if(target == 0)
        {
            res.emplace_back(track);
            return;
        }
        for(decltype(candidates.size()) i = begin; i < candidates.size(); ++i)
        {
            if(target - candidates[i] < 0)
            {
                return;
            }

            cout << "选择之前的track值："; 
            print(track);
            cout << "，剩余目标值：" << target << endl;
            
            track.emplace_back(candidates[i]);
            backTrack(candidates, track, target - candidates[i], i);

            cout << "选择之后的track值：";
            print(track);
            cout << "，剩余目标值：" << target - candidates[i] << endl;

            track.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> track;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, track, target, 0);
        return res;
    }

};

int main()
{
    Solution solution;
    vector<int> candidates= {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    return 0;
}