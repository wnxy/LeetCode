/**
 * @file 373.find_k_pairs_with_smallest_sums.cpp
 * @author your name (you@domain.com)
 * @brief Top K 问题
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct combination
{
    /* data */
    int x;
    int y;
    combination(int x_, int y_) : x(x_), y(y_) {}
    bool operator< (const combination& comb) const
    {
        return x + y < comb.x + comb.y;
    }
};


class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        // 大顶堆，寻找TopＫ小元素
        priority_queue<combination> heap;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int sum = nums1[i] + nums2[j];
                if (heap.size() >= k)
                {
                    if (!heap.empty() && heap.top().x + heap.top().y > sum)
                    {
                        heap.pop();
                        heap.push(combination(nums1[i], nums2[j]));
                    }
                }
                else
                {
                    heap.push(combination(nums1[i], nums2[j]));
                }
            }
        }
        while (!heap.empty())
        {
            auto tmp = heap.top();
            res.push_back({tmp.x, tmp.y});
            heap.pop();
        }
        return res;
    }
};

int main()
{
    // nums1 = [1,7,11], nums2 = [2,4,6], k = 3
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    int k = 5;
    Solution solution;
    vector<vector<int>> res = solution.kSmallestPairs(nums1, nums2, k);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}