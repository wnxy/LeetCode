/**
 * @file 67.offer67.cpp
 * @author your name (you@domain.com)
 * @brief 把字符串转换成整数
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        if(str.empty())
        {
            return 0;
        }
        int n = str.length(), idx = 0;
        long res = 0;
        // 去除前导空格
        while(idx < n && str[idx] == ' ')
        {
            ++idx;
        }
        int sign = 1;    // 数字符号位，1正     -1负
        if(idx < n && str[idx] == '+')
        {
            sign = 1;
            ++idx;
        }
        else if(idx < n && str[idx] == '-')
        {
            sign = -1;
            ++idx;
        }
        if(idx < n && !isdigit(str[idx]))
        {
            return 0;
        }
        else
        {
            while(idx < n && isdigit(str[idx]))
            {
                res *= 10;
                res += str[idx] - '0';
                ++idx;
                // if(res > (long)abs(INT_MIN))
                // {
                //     return sign == 1? INT_MAX: INT_MIN; 
                // }
            }
        }
        return res * sign;
    }
};

int main()
{
    string str = "-91283472332";
    Solution solution;
    cout << solution.strToInt(str) << endl;
    return 0;
}