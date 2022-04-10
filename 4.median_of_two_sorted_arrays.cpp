/**
 * @file 4.median_of_two_sorted_arrays.cpp
 * @author your name (you@domain.com)
 * @brief 寻找两个正序数组中的中位数
 * @version 0.1
 * @date 2022-04-05
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty())   // 中位数在nums2中
        {
            vector<int> tmp = findMedian(nums2);
            if(nums2.size() % 2 == 1)
            {
                return tmp[0];
            }
            else
            {
                return (tmp[0] + tmp[1]) / 2.0;
            }
        }
        if(nums2.empty())   // 中位数在nums1中
        {
            vector<int> tmp = findMedian(nums1);
            if(nums1.size() % 2 == 1)
            {
                return tmp[0];
            }
            else
            {
                return (tmp[0] + tmp[1]) / 2.0;
            }
        }
        if(nums2[0] >= nums1[nums1.size() - 1])    // nums2可以接在nums1的后面
        {
            return findTwoMedian(nums1, nums2);
        }
        if(nums1[0] >= nums2[nums2.size() - 1])    // nums1可以接在nums2的后面
        {
            return findTwoMedian(nums2, nums1);
        }
        vector<int> tmp1 = findMedian(nums1);
        vector<int> tmp2 = findMedian(nums2);
        tmp1.insert(tmp1.end(), tmp2.begin(), tmp2.end());
        sort(tmp1.begin(), tmp1.end());
        tmp2 = findMedian(tmp1);
        if(tmp2.size() == 1)
        {
            return tmp2[0];
        }
        return (tmp2[0] + tmp2[1]) / 2.0;
    }

    vector<int> findMedian(vector<int>& nums)
    {
        vector<int> res;
        if(nums.size() % 2 == 1)
        {
            return {nums[nums.size() / 2]};
        }
        //double median = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
        //return median;
        return {nums[nums.size() / 2], nums[nums.size() / 2 - 1]};
    }

    double findTwoMedian(vector<int>& nums1, vector<int>& nums2)
    {
        int len = nums1.size() + nums2.size();
        if(len % 2 == 1)
        {
            if((len / 2) < nums1.size())
            {
                return nums1[len / 2];
            }
            else
            {
                return nums2[len / 2 - nums1.size()];
            }
        }
        else
        {
            int l = len / 2 - 1;
            int r = len / 2;
            double median;
            if(r < nums1.size())   // 中位数均在nums1中
            {
                median = (nums1[l] + nums2[r]) / 2.0;
            }
            else if(l >= nums1.size())   // 中位数均在nums2中
            {
                median = (nums2[l - nums1.size()] + nums2[r - nums1.size()]) / 2.0;
            }
            else
            {
                median = (nums1[l] + nums2[r - nums1.size()]) / 2.0;
            }
            return median;
        }
    }
};

int main()
{
    vector<int> nums1 = {4};
    vector<int> nums2 = {1, 2, 3};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}