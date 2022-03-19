/*
* 无重复字符的最长字串
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len < 2) return len;
        int left = 0, right = 1, res = 0;
        unordered_map<char, int> dict;   //存储滑动窗口内的字符
        dict[s[0]] = 1;
        while(right < len)
        {
            // 滑动窗口无重复元素，窗口增大
            if(dict[s[right]] == 0)
            {
                res = max(res, right - left + 1);
                dict[s[right]] = 1;
                ++right;
            }
            else  // 滑动窗口中有重复元素，窗口缩小
            {
                while(left < right && dict[s[right]] != 0)
                {
                    //dict.erase(s[left]);
                    dict[s[left]] = 0;
                    ++left;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string str = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(str) << endl;
    return 0;
}