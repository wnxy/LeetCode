/**
 * @file 448.find_all_numbers_disappeared_in_an_array.cpp
 * @author your name (you@domain.com)
 * @brief 找到所有数组中消失的数字
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.empty()) return {};
        int n = nums.size();
        vector<int> res;
        unordered_set<int> dic;
        for(int i = 0; i < n; ++i)
        {
            dic.insert(nums[i]);
        }
        for(int i = 1; i <= n; ++i)
        {
            if(!dic.count(i) > 0)
            {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution solution;
    vector<int> res = solution.findDisappearedNumbers(nums);
    return 0;
}