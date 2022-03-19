/**
 * @file alibaba_1.cpp
 * @author your name (you@domain.com)
 * @brief 牛客阿里巴巴模拟真题第一题
 * 小强现在有n个物品,每个物品有两种属性xi和yi.他想要从中挑出尽可能多的物品满足以下条件:
 * 对于任意两个物品i和j,满足xi < xj 且 yi < yj或者 xi > xj 且 yi > yj.问最多能挑出多少物品.
 * 进阶：时间复杂度，空间复杂度
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct object
{
    /* data */
    int x;
    int y;
    object(): x(0), y(0) {}
    bool operator< (const object& tmp) const
    {
        if(x == tmp.x) return y > tmp.y;
        return x < tmp.x;
    }
};

/**
 * @brief 寻找给定数组的最长递增子序列
 * 
 * @param obj 
 * @return int 
 */
int lengthOfSub(vector<object>& obj)
{
    int n = obj.size();
    if(n < 2) return n;
    vector<int> vec(n + 1);
    int len = 1;
    vec[len] = obj[0].y;
    for(int i = 0; i < n; ++i)
    {
        if(obj[i].y > vec[len])
        {
            vec[++len] = obj[i].y;
        }
        else 
        {
            // pos变量表示插入位置
            int left = 1, right = len, pos = 0;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(vec[mid] < obj[i].y)
                {
                    pos = mid;
                    left = mid  + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            vec[pos + 1] = obj[i].y;
        }
    }
    return len;
}


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<object> vec(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> vec[i].x;
        }
        for(int i = 0; i < n; ++i)
        {
            cin >> vec[i].y;
        }
        sort(vec.begin(), vec.end());
        cout << lengthOfSub(vec) << endl; 
    }
    return 0;
}