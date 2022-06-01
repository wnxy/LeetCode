/**
 * @file 438.find_all_anagrams_in_a_string.cpp
 * @author your name (you@domain.com)
 * @brief 找到字符串中所有字母异位词
 * @version 0.1
 * @date 2022-05-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        if(s_len < p_len) return {};
        int left = 0, right = 0;
        int start = 0, valid = 0;
        vector<int> res;
        unordered_map<char, int> substr, window;
        for(char c: p)
        {
            ++substr[c];
        }
        while(right < s_len)
        {
            char c = s[right];
            ++right;
            // 扩大窗口
            if(substr.count(c))
            {
                ++window[c];
                if(window[c] == substr[c])
                {
                    ++valid;
                }
            }
            // 缩小窗口
            while(valid == substr.size())
            {
                res.emplace_back(right - p_len);
                char d = s[left];
                ++left;
                if(substr.count(d))
                {
                    --window[d];
                    if(window[d] < substr[d])
                    {
                        --valid;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution solution;
    vector<int> res = solution.findAnagrams(s, p);
    return 0;
}