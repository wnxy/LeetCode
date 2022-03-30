/**
 * @file 239.sliding_window_maximum.cpp
 * @author your name (you@domain.com)
 * @brief 滑动窗口的最大值
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k == 1) return nums;
        priority_queue<int, vector<int>, less<int>> heap;   // 实现一个大顶堆，寻找滑动窗口的最大值
        int left, right = 0;    // 定义左右双指针当作滑动窗口的左右边界
        int len = nums.size();
        vector<int> res;
        for(left = 0; left <= len - k; ++left)
        {
            if(heap.empty())
            {
                while(heap.size() < k)
                {
                    heap.push(nums[right++]);
                }
            }
            else
            {
                while(heap.size() >= k && nums[left - 1] == heap.top())
                {
                    heap.pop();
                }
                heap.push(nums[right++]);
            }
            res.emplace_back(heap.top());
        }
        return res;
    }
};

class Solution2 {
public:
    // 如果first值不相等则按first升序排列，否则按second升序排列
    struct compare
    {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b)
        {
            if(a.first != b.first)
            {
                return a.first < b.first;
            }
            else
            {
                return a.second < b.second;
            }
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k == 1) return nums;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;   // 实现一个大顶堆，寻找滑动窗口的最大值
        vector<int> res;
        // 建立一个大小为k的堆
        for(int i = 0; i < k; ++i)
        {
            heap.push({nums[i], i});
        }
        res.emplace_back(heap.top().first);
        for(int i = k; i < nums.size(); ++i)
        {
            while(i - heap.top().second >= k)
            {
                heap.pop();
            }
            heap.push({nums[i], i});
            res.emplace_back(heap.top().first);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    int k = 4;
    Solution2 solution;
    vector<int> res = solution.maxSlidingWindow(nums, k);
    return 0;
}