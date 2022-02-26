/**
 * @file 76.minimum_window_substring.cpp
 * @author your name (you@domain.com)
 * @brief 最小覆盖子串
 * @version 0.1
 * @date 2022-02-26
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
    string minWindow(string s, string t) {
        int sl = s.length(), needCount = t.length();
        if(sl < needCount) return "";
        vector<int> need(128, 0);
        for(char c : t)
        {
            need[c]++;
        }
        //i表示滑动窗口左边界，j表示滑动窗口右边界
        int i = 0, j = 0, start = 0, len = INT_MAX;
        while(j < sl)
        {
            //扩大滑动窗口
            char c = s[j];
            if(need[c] > 0)
            {
                needCount--;
            }
            need[c]--;
            
            if(needCount == 0)
            {
                //缩小滑动窗口
                while(i < j && need[s[i]] < 0)
                {
                    need[s[i++]]++;
                }
                //更新答案
                if(j < sl && j - i + 1 < len)
                {
                    start = i;
                    len = j - i + 1;
                }
                need[s[i]]++;
                needCount++;
                i++;
            }
            j++;
        }
        return len == INT_MAX? "": s.substr(start, len);
    }
};

int main()
{
    Solution solution;
    string s = "DOABECODEBANC";
    string t = "ABC";
    cout << solution.minWindow(s, t) << endl;
    return 0;
}