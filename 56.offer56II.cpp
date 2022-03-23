/**
 * @file 56.offer56II.cpp
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
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};  //int型整数四个字节
        for(int num: nums)
        {
            long bit = 1;
            for(int i = 0; i < 32; ++i)
            {
                count[i] += bit & num? 1: 0;
                bit <<= 1;
            }
        }
        int res = 0;
        for(int i = 0; i < 32; ++i)
        {
            res |= (count[i] % 3) << i;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 4, 3, 3};
    cout << solution.singleNumber(nums) << endl;
    return 0;
}