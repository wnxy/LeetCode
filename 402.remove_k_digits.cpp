/**
 * @file 402.remove_k_digits.cpp
 * @author your name (you@domain.com)
 * @brief 移除k位数字，使得剩下的数字组成的数最小
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    //单调栈，寻找前一个大于等于当前元素的值
    string removeKdigits(string num, int k) {
        deque<char> stk;
        int count = k;
        string ans = "";
        for(auto n : num)
        {
            //满足条件出栈
            while(!stk.empty() && n < stk.back() && count > 0)
            {
                stk.pop_back();
                --count;
            }
            stk.push_back(n);
        }
        //如果k位数字没有移除完毕，将剩下的数字从末尾移除
        while(count--)
        {
            stk.pop_back();
        }
        while(!stk.empty() && stk.front() == '0')
        {
            stk.pop_front();
        }
        while(!stk.empty())
        {
            ans += stk.front();
            stk.pop_front();
        }
        return ans == ""? "0": ans;
    }
};

int main()
{
    Solution solution;
    string num = "10";
    int k = 2;
    cout << solution.removeKdigits(num, k) << endl;
    return 0;
}