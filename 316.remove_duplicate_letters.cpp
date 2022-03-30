/**
 * @file 316.remove_duplicate_letters.cpp
 * @author your name (you@domain.com)
 * @brief 去除重复字母
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> dict;     // 统计字符串中各字符出现的次数
        for(char c: s)
        {
            ++dict[c];
        }
        deque<char> dq;     // 模拟单调递增栈
        for(int i = 0; i < s.length(); ++i)
        {
            //char tmp = dq.back();
            while(!dq.empty() && dq.back() > s[i] && dict[dq.back()] > 1)
            {
                //char tmp = dq.back();
                --dict[dq.back()];
                dq.pop_back();
            }
            dq.push_back(s[i]);
        }
        string res = "";
        for(int i = 0; i < dq.size(); ++i)
        {
            res += dq[i];
        }
        return res;
    }
};

class Solution2 {
public:
    string smallestSubsequence(string s) {
        vector<bool> visited(26, false);    // 标志单调栈中是否存在某个元素
        unordered_map<char, int> dict;    // 统计各个字符还剩下多少
        for(char c: s)
        {
            ++dict[c];
        }
        deque<char> dq;     // 双端队列模拟单调递增栈
        for(int i = 0; i < s.length(); ++i)
        {
            if(!dq.empty() && visited[s[i] - 'a'] == true)
            {
                --dict[s[i]];
                continue;
            }
            while(!dq.empty() && dq.back() > s[i] && dict[dq.back()] > 0)
            {
                visited[dq.back() - 'a'] = false;
                dq.pop_back();
            }
            dq.push_back(s[i]);
            --dict[s[i]];
            visited[s[i] - 'a'] = true;
        }
        string res = "";
        for(int i = 0; i < dq.size(); ++i)
        {
            res += dq[i];
        }
        return res;
    }
};

int main()
{
    string s = "bcbcbcababa";
    Solution2 solution;
    //string res = solution.removeDuplicateLetters(s);
    string res = solution.smallestSubsequence(s);
    cout << res << endl;
    return 0;
}