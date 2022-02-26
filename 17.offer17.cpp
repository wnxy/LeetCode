/**
 * @file 17.offer17.cpp
 * @author your name (you@domain.com)
 * @brief 打印从1到最大的n位数
 * 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
 * @version 0.1
 * @date 2022-02-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    vector<string> res;
    string str;
    char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<string> printNumber(int n)
    {
        for(int i = 1; i <= n; ++i)
        {
            dfs(0, i);
        }
        return res;
    }

    // x表示正在处理第几位数（从左到右），len表示生成数的长度
    void dfs(int x, int len)
    {
        if(x == len)
        {
            res.emplace_back(str);
            return;
        }
        int start = (x == 0? 1: 0);
        for(int i = start; i < 10; ++i)
        {
            str.push_back(num[i]);
            dfs(x + 1, len);
            str.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    for(auto str: solution.printNumber(5))
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}