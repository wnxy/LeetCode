/**
 * @file 20.offer20.cpp
 * @author your name (you@domain.com)
 * @brief 表示数值的字符串
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        int start = 0, end = s.length() - 1;
        while(start < s.length() && s[start] == ' ') ++start;
        while(end >= 0 && s[end] == ' ') --end;
        
        if(start > end) return false;
        string tmp = s.substr(start, end - start + 1);
        int loc1 = tmp.find('e');
        int loc2 = tmp.find('E');
        start = 0;
        end = tmp.length() - 1;
        if(loc1 != tmp.npos && loc2 != tmp.npos)
        {
            return false;
        }
        else if(loc1 == tmp.npos && loc2 == tmp.npos)
        {
            return isDecimal(tmp) || isInteger(tmp);
        }
        else if(loc1 != tmp.npos)
        {
            return (isDecimal(tmp.substr(start, loc1 - start)) || isInteger(tmp.substr(start, loc1 - start))) && 
            isInteger(tmp.substr(loc1 + 1, end - loc1 + 1));
        }
        else if(loc2 != tmp.npos)
        {
            return (isDecimal(tmp.substr(start, loc2 - start)) || isInteger(tmp.substr(start, loc2 - start))) && 
            isInteger(tmp.substr(loc2 + 1, end - loc2 + 1));
        }
        return false;
    }

    // 判断是否是小数
    bool isDecimal(string s)
    {
        if(s.empty()) return false;
        int start = 0, len = s.length();
        if(s[0] == '-' || s[0] == '+') ++start;
        int loc = s.find('.');
        if(loc == s.npos) return false;
        if(loc == start)
        {
            return isInteger(s.substr(loc + 1, len - loc - 1));
        }
        else if(loc == len - 1)
        {
            return isInteger(s.substr(start, loc - start));
        }
        return isInteger(s.substr(start, loc - start)) && isInteger(s.substr(loc + 1, len - loc - 1));
    }

    // 判断是否是整数
    bool isInteger(string s)
    {
        if(s.empty()) return false;
        int start = 0, len = s.length();
        if(s[0] == '-' || s[0] == '+') ++start;
        for(int i = start; i < len; ++i)
        {
            if(s[i] > '9' || s[i] < '0')
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s = "+-.";
    cout << solution.isNumber(s) << endl;
    return 0;
}