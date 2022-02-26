/**
 * @file 31.next_permutation.cpp
 * @author your name (you@domain.com)
 * @brief 下一个排列
 * @version 0.1
 * @date 2022-02-22
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
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        //从后向前寻找第一个升序对
        int j = -1;
        for(int i = len - 1; i >= 0; --i)
        {
            if(nums[i] > nums[i - 1])
            {
                j = i - 1;
                break;
            }
        }
        //从后向前寻找第一个比nums[j]大的数
        if(j >= 0)
        {
            for(int i = len - 1; i > j; --i)
            {
                if(nums[i] > nums[j])
                {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
            reverse(nums.begin() + 1 + j, nums.end());
            return;
        }
        
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 2, 1};
    solution.nextPermutation(nums);
    return 0;
}