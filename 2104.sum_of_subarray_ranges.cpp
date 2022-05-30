/**
 * @file 2104.sum_of_subarray_ranges.cpp
 * @author your name (you@domain.com)
 * @brief 子数组的范围和
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);   // 左边寻找大于等于
        vector<int> right(n, n);   // 右边寻找严格大于
        stack<int> stk;
        ll res = 0;
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && nums[stk.top()] < nums[i])
            {
                right[stk.top()] = i;
                stk.pop();
            }
            if(!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        for(int i = 0; i < n; ++i)
        {
            int l = left[i] + 1, r = right[i] - 1;
            res += ((ll)nums[i] * (i - l + 1) * (r - i + 1));
        }
        while(!stk.empty()) stk.pop();
        fill(left.begin(), left.end(), -1);
        fill(right.begin(), right.end(), n);
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && nums[stk.top()] > nums[i])
            {
                right[stk.top()] = i;
                stk.pop();
            }
            if(!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        ll tmp = 0;
        for(int i = 0; i < n; ++i)
        {
            int l = left[i] + 1, r = right[i] - 1;
            tmp += ((ll)nums[i] * (i - l + 1) * (r - i + 1));
        }
        return res - tmp;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution solution;
    cout << solution.subArrayRanges(nums) << endl;
    return 0;
}