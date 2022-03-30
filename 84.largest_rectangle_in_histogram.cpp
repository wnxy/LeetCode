/**
 * @file 84.largest_rectangle_in_histogram.cpp
 * @author your name (you@domain.com)
 * @brief 柱状图中的最大矩形
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 暴力解法，枚举每一个元素，寻找当前元素前一个更小的元素，寻找当前元素后一个更小的元素
 * 
 */
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int len = heights.size();
        int min_left_index = 0, min_right_index = len - 1;
        for(int i = 0; i < len; ++i)
        {
            min_left_index = 0; 
            min_right_index = len - 1;
            // 向左搜小于当前元素的元素
            for(int j = i; j >= 0; --j)
            {
                min_left_index = heights[min_left_index] > heights[j]? j: min_left_index;
            }
            // 向右搜小于当前元素的元素
            for(int j = i; j < len; ++j)
            {
                min_right_index = heights[min_right_index] > heights[j]? j: min_right_index;
            }
            int w = min_right_index - min_left_index;
            res = max(res, heights[i] * w);
        }
        return res;
    }
};

/**
 * @brief 动态规划
 * 
 */
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int len = heights.size();
        vector<int> tmp(len + 2, 0);
        for(int i = 1; i <= len; ++i)
        {
            tmp[i] = heights[i];
        }
        vector<int> min_left_index(len + 2);    // 当前元素的前一个更小元素的下标
        vector<int> min_right_index(len + 2);   // 当前元素的后一个更小元素的下标
        // 从左向右找
        for(int i = 1; i < len + 2; ++i)
        {
            min_left_index[i] = tmp[min_left_index[i - 1]] > tmp[i]? i: min_left_index[i - 1];
        }
        for(int n: min_left_index)
        {
            cout << n << " ";
        }
        cout << endl;
        // 从右向左找
        for(int i = len; i >= 0; --i)
        {
            min_right_index[i] = tmp[min_right_index[i + 1]] > tmp[i]? i: min_right_index[i + 1];
        }
        for(int n: min_right_index)
        {
            cout << n << " ";
        }
        cout << endl;
        for(int i = 1; i <= len; ++i)
        {
            int w = min_right_index[i] - min_left_index[i];
            res = max(res, tmp[i] * w);
        }
        return res;
    }
};

int main()
{
    Solution2 solution;
    vector<int> heights = {2,1,5,6,2,3};
    int res = solution.largestRectangleArea(heights);
    cout << res << endl;
    return 0;
}