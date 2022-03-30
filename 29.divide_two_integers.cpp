/**
 * @file 29.divide_two_integers.cpp
 * @author your name (you@domain.com)
 * @brief 两数相除
 * @version 0.1
 * @date 2022-03-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(dividend == INT_MIN)    // 被除数为整数最小值
        {
            if(divisor == 1) return dividend;
            else if(divisor == -1) return INT_MAX;   // 处理溢出
        }
        if(divisor == INT_MIN)     // 除数为整数最小值
        {
            if(dividend == INT_MIN) return 1;
            else if(dividend > INT_MIN) return 0;
        }
        // 将除数和被除数均转换为负数，避免溢出
        int a = dividend > 0? -dividend: dividend;     // 被除数转换为负数
        int b = divisor > 0? -divisor: divisor;        // 除数转换为负数
        int sign_a = dividend > 0? 0: 1;     // 被除数的符号，0正1负
        int sign_b = divisor > 0? 0: 1;      // 除数的符号，0正1负
        if(a == b) return (sign_a ^ sign_b) == 0? 1: -1;
        int res = 0;
        while(a <= b)
        {
            int step = 1, tmp = b;
            while(a <= tmp)
            {
                a -= tmp;
                //tmp = -((-tmp) << 1);
                //tmp = (unsigned int)tmp << 1;
                tmp <<= 1;
                res += step;
                step <<= 1;
            }
        }
        return (sign_a ^ sign_b) == 0? res: -res;
    }
};

int main()
{
    Solution solution;
    // 1100540749
    // -1090366779
    int dividend = 1100540749;
    int divisor = -1090366779;
    //cout << solution.divide(dividend, divisor) << endl;
    cout << INT_MAX << endl;
    return 0;
}