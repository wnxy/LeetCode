/**
 * @file 34.find_first_and_last_position.cpp
 * @author your name (you@domain.com)
 * @brief 在排序数组中查找元素的第一个和最后一个位置
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int exist = 0, left = 0, right = nums.size() - 1;
        while(left <= right && nums[left] != nums[right])
        {
            int mid = left + ((right - left) / 2);
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                exist = 1;
                if(nums[right] != target)
                {
                    --right;
                }
                else if(nums[left] != target)
                {
                    ++left;
                }
                else
                {
                    break;
                }
            }
        }
        if(exist)
        {
            res[0] = left;
            res[1] = right;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {5, 7};
    vector<int> res = solution.searchRange(nums , 7);
    return 0;
}