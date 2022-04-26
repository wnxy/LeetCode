/**
 * @file 224.basic_calculator.cpp
 * @author your name (you@domain.com)
 * @brief 基本计算器
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        int len = s.length();
        // 运算符的优先级
        unordered_map<char, int> priority = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2}
        };
        vector<string> reverseExp;    // 逆波兰表达式
        stack<char> op;    // 操作符栈
        string num = "";
        // 求解逆波兰式
        for(int i = 0; i < len; ++i)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num += s[i];
                if(i + 1 == len || !isdigit(s[i + 1]))
                {
                    reverseExp.emplace_back(num);
                    num.clear();
                }
            }
            if(s[i] == '(')
            {
                op.push(s[i]);
            }
            // 如果当前字符为运算符
            while(priority.count(s[i]))
            {
                // if(!num.empty())
                // {
                //     reverseExp.emplace_back(num);
                //     num.clear();
                // }
                if(i == 0 || (!isspace(s[i - 1]) && !isdigit(s[i - 1])))
                {
                    reverseExp.push_back(to_string(0));
                }
                if(op.empty() || op.top() == '(' || priority[s[i]] > priority[op.top()])
                {
                    op.push(s[i]);
                    break;
                }
                else
                {
                    string opStr;
                    opStr += op.top();
                    op.pop();
                    reverseExp.emplace_back(opStr);
                }
            }
            if(s[i] == ')')
            {
                while(!op.empty() && op.top() != '(')
                {
                    string opStr;
                    opStr += op.top();
                    op.pop();
                    reverseExp.emplace_back(opStr);
                }
                op.pop();
            }
        }
        if(!num.empty())
        {
            reverseExp.emplace_back(num);
            num.clear();
        }
        while(!op.empty())
        {
            string opStr;
            opStr += op.top();
            op.pop();
            reverseExp.emplace_back(opStr);
        }

        // 计算逆波兰式的值
        stack<int> numStk;
        for(string str: reverseExp)
        {
            if(str == "+" || str == "-" || str == "*" || str == "/")
            {
                int num2 = numStk.top();
                numStk.pop();
                // int num1;
                // if(!numStk.empty())
                // {
                //     num1 = numStk.top();
                //     numStk.pop();
                // }
                // else
                // {
                //     num1 = 0;
                // }
                int num1 = numStk.top();
                numStk.pop();
                numStk.push(calc(num1, num2, str));
            }
            else
            {
                numStk.push(stoi(str));
            }
        }
        return numStk.top();
    }

    int calc(int num1, int num2, string op)
    {
        if(op == "+")
        {
            return num1 + num2;
        }
        else if(op == "-")
        {
            return num1 - num2;
        }
        else if(op == "*")
        {
            return num1 * num2;
        }
        else 
        {
            return num1 / num2;
        }
    }
};

int main()
{
    string s = "1 + 1";
    Solution solution;
    cout << solution.calculate(s) << endl;
    //cout << stoi("-23") << endl;
    return 0;
}