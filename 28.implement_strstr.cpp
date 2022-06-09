/**
 * @file 28.implement_strStr().cpp
 * @author your name (you@domain.com)
 * @brief 字符串匹配KMP算法
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void getNext(string& p, vector<int>& next)
    {
        int n = p.length();
        next[0] = -1;
        int i = 0, j = -1;
        while(i < n)
        {
            if(j == -1 || p[i] == p[j])
            {
                ++i;
                ++j;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
    }

    int strStr(string haystack, string needle) {
        int i = 0, j = 0;  // i匹配主串，j匹配子串
        vector<int> next(needle.length() + 1, 0);
        getNext(needle, next);
        while(i < (int)haystack.length() && j < (int)needle.length())
        {
            if(j == -1 || haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        if(j == needle.length())
        {
            return i - j;
        }
        return -1;
    }
};

int main()
{
    string haystack = "hello";
    string needle = "ll";
    Solution solution;
    cout << solution.strStr(haystack, needle) << endl;
    return 0;
}