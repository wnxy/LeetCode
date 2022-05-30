/**
 * @file 42.trapping_rain_water.cpp
 * @author your name (you@domain.com)
 * @brief 接雨水
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n = height.size();
        for(int i = 0; i < n; ++i)
        {
            int left = i - 1, right = i + 1;
            while(left >= 0)
            {
                if(height[left] >= height[i])
                {
                    break;
                }
                --left;
            }
            while(left >= 0 && right < n)
            {
                if(height[right] > height[i])
                {
                    break;
                }
                ++right;
            }
            if(left >= 0 && right < n)
            {
                res += (right - left - 1) * (min(height[left], height[right]) - height[i]);
            }  
        }
        return res;
    }
};

class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1)
        {
            return 0;
        }
        int res = 0;
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && height[stk.top()] < height[i])
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
            cout << i << '\t';
        }
        cout << endl;
        for(int i = 0; i < n; ++i)
        {
            cout << left[i] << '\t';
        }
        cout << endl;
        for(int r: right)
        {
            cout << r << '\t';
        }
        cout << endl;
        for(int i = 0; i < n; ++i)
        {
            if(left[i] != -1 && right[i] != n)
            {
                res += (right[i] - left[i] - 1) * (min(height[left[i]], height[right[i]]) - height[i]);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    cout << solution.trap(height) << endl;
    return 0;
}