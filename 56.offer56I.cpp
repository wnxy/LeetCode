/**
 * @file 56.offer56.cpp
 * @author your name (you@domain.com)
 * @brief 数组中数字出现的次数
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        if(nums.size() < 3) return nums;
        vector<int> res;
        int n = 0, bitNum = 0;
        // 全部异或，得到异或结果
        for(int num : nums) 
            n ^= num;
        while(n)
        {
            if(n % 2 == 1)
            {
                break;
            }
            ++bitNum;
            n /= 2;
        }
        vector<int> nums1;  // bitNum位为0，则分为第一组
        vector<int> nums2;  // bitNum位为1，则分为第二组
        for(int num : nums)
        {
            int bit = 0, count = bitNum, numTmp = num;
            while(count >= 0)
            {
                bit = numTmp % 2;
                numTmp /= 2;
                --count;
            }
            if(bit == 0) nums1.emplace_back(num);
            else nums2.emplace_back(num);
        }
        n = 0;
        for(int num: nums1) n ^= num;
        res.emplace_back(n);
        n = 0;
        for(int num: nums2) n ^= num;
        res.emplace_back(n);
        return res;
    }
};

int main()
{
    vector<int> nums = {1,2,10,4,1,4,3,3};
    Solution solution;
    vector<int> res = solution.singleNumbers(nums);

    return 0;
}