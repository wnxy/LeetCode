/**
 * @file 394.decode_string.cpp
 * @author your name (you@domain.com)
 * @brief 字符串解码
 * @version 0.1
 * @date 2022-03-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        string res = "";
        stack<int> count; // 字符串解码次数栈
        stack<char> stk;  // 字符串解码字符栈
        for (int i = 0; i < s.length();)
        {
            string num = "";
            // []内的字符出现次数
            while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            {
                num += s[i];
                ++i;
            }
            if(num != "")
            {
                count.push(stoi(num));
            }
            // 解析[]内的字符
            while (i < s.length() && (s[i] == '[' || (s[i] >= 'a' && s[i] <= 'z')))
            {
                stk.push(s[i]);
                ++i;
            }
            if (s[i] == ']')
            {
                string tmp = "";
                while (i < s.length() && stk.top() != '[')
                {
                    tmp = stk.top() + tmp;
                    stk.pop();
                }
                stk.pop(); // pop掉站内的[括号
                ++i;
                for (int j = 0; j < count.top(); ++j)
                {
                    for (char c : tmp)
                    {
                        stk.push(c);
                    }
                }
                count.pop();
            }
        }
        while (!stk.empty())
        {
            if (stk.top() != '[')
            {
                res = stk.top() + res;
            }
            stk.pop();
        }
        return res;
    }
};

int main()
{
    string s = "3[a2[c]]";
    Solution solution;
    string res = solution.decodeString(s);
    cout << res << endl;
    return 0;
}