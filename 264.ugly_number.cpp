/**
 * @file 264.ugly_number.cpp
 * @author your name (you@domain.com)
 * @brief 丑数 II
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        priority_queue<long, vector<long>, greater<long>> heap;   //小顶堆
        unordered_map<long, long> dict;      //哈希表去重
        vector<int> factors = {2, 3, 5};
        heap.emplace(1);
        dict[1] = 1;
        int res = 1;
        for(int i = 2; i <= n; ++i)
        {
            res = heap.top();
            heap.pop();
            dict.erase(res);
            for(int factor : factors)
            {
                int x = res * factor;
                if(dict.count(x) == 0)
                {
                    dict[x] = 1;
                    heap.emplace(x);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    int n = 10;
    cout << solution.nthUglyNumber(n) << endl;
    return 0;
}