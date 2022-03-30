/**
 * @file 51.offer51.cpp
 * @author your name (you@domain.com)
 * @brief 数组中的逆序对
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        // 新建一个数组，避免修改原始数组
        vector<int> copy(nums.begin(), nums.end());

        vector<int> tmp;
        return reversePairs(copy, 0, len - 1, tmp);
    }

    /**
     * @brief nums[left, right]计算逆序对个数并且排序
     * 
     * @param nums 
     * @param left 
     * @param right 
     * @param tmp 
     * @return int 
     */
    int reversePairs(vector<int>& nums, int left, int right, vector<int>& tmp) {
        if(left == right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int leftPairs = reversePairs(nums, left, mid, tmp);
        int rightPairs = reversePairs(nums, mid + 1, right, tmp);
        if(nums[mid] <= nums[mid + 1]) {
            return leftPairs + rightPairs;
        }

        int crossPairs = mergeAndCount(nums, left, mid, right, tmp);
        return leftPairs + crossPairs + rightPairs;
    }

    /**
     * @brief nums[left, mid]有序，nums[mid + 1, right]有序
     * 
     * @param nums 
     * @param left 
     * @param mid 
     * @param right 
     * @param tmp 
     * @return int 
     */
    int mergeAndCount(vector<int>& nums, int left, int mid, int right, vector<int>& tmp) {
        tmp = nums;

        int i = left;
        int j = mid + 1;
        int count = 0;
        for(int k = left; k <= right; ++k) {
            if(i == mid + 1) {
                nums[k] = tmp[j];
                ++j;
            } else if(j == right + 1) {
                nums[k] = tmp[i];
                ++i;
            }else if(tmp[i] <= tmp[j]) {
                nums[k] = tmp[i];
                ++i;
            }else {
                nums[k] = tmp[j];
                ++j;
                count += mid - i + 1;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {7, 5, 6, 4};
    Solution solution;
    cout << solution.reversePairs(nums);
    return 0;
}