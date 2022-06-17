/**
 * @file 647.palindromic_substrings.cpp
 * @author your name (you@domain.com)
 * @brief 回文子串
 * @version 0.1
 * @date 2022-06-13
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
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        for(int center = 0; center < 2 * n - 1; ++center)
        {
            int left = center / 2;
            int right = left + (center % 2);
            while(left <= right && left < n && right >= 0 && s[left] == s[right])
            {
                ++res;
                ++left;
                --right;
            }
        }
        return res;
    }
};

int main()
{
    string s = "aaa";
    Solution solution;
    cout << solution.countSubstrings(s) << endl;
    return 0;
}