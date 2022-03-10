/**
 * @file 229.majority_element_II.cpp
 * @author your name (you@domain.com)
 * @brief 求众数
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> count;
        for(int num : nums)
        {
            count[num]++;
        }
        int len = nums.size() / 3;
        for(auto it = count.begin(); it != count.end(); ++it)
        {
            if(it->second > len)
            {
                res.emplace_back(it->first);
            }
        }
        return res;
    }
};

class Solution1 {
public:
    //摩尔投票计数法
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int cand1 = nums[0], count1 = 0;
        int cand2 = nums[0], count2 = 0;
        int len = nums.size() / 3;
        // 投票阶段，选出最多2个满足条件的元素
        for(int num : nums)
        {
            if(cand1 == num)
            {
                ++count1;
            }
            else if(cand2 == num)
            {
                ++count2;
            }
            else if(count1 == 0)
            {
                cand1 = num;
                ++count1;
            }
            else if(count2 == 0)
            {
                cand2 = num;
                ++count2;
            }
            else
            {
                --count1;
                --count2;
            }
        }
        // 验证阶段，验证选出的元素是否满足条件
        count1 = 0;
        count2 = 0;
        for(int num : nums)
        {
            if(cand1 == num) 
                ++count1;
            else if(cand2 == num) 
                ++count2;
        }
        if(count1 > len) res.emplace_back(cand1);
        if(count2 > len) res.emplace_back(cand2);
        return res;
    }
};

int main()
{
    Solution1 solution;
    vector<int> nums = {6, 5, 5};
    for(int num : solution.majorityElement(nums))
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}