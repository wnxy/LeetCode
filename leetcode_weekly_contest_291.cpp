/**
 * @file leetcode291.cpp
 * @author your name (you@domain.com)
 * @brief leetcode 第291场周赛
 * @version 0.1
 * @date 2022-05-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// 周赛第一题
// #include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// using namespace std;

// class Solution {
// public:
//     string max(const string& s1, const string& s2)
//     {
//         if(s1.empty()) return s2;
//         if(s2.empty()) return s1;
//         return s1 < s2? s2: s1;
//     }
//     string split(string& s, int i)
//     {
//         if(s.empty()) return "";
//         string res = "";
//         for(int j = 0; j < s.size(); ++j)
//         {
//             if(j != i)
//             {
//                 res += s[j];
//             }
//         }
//         return res;
//     }
//     string removeDigit(string number, char digit) {
//         string res = "";
//         for(int i = 0; i < number.size(); ++i)
//         {
//             if(number[i] == digit)
//             {
//                 res = max(res, split(number, i));
//             }
//         }
//         return res;
//     }
// };

// int main()
// {
//     string number = "123";
//     char digit = '3';
//     Solution solution;
//     string res = solution.removeDigit(number, digit);
//     cout << res << endl;
//     return 0;
// }


// 周赛第二题
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     int distance(vector<int>& nums)
//     {
//         int n = nums.size();
//         if(n < 2) return INT_MAX;
//         int res = INT_MAX;
//         for(int i = 1; i < n; ++i)
//         {
//             res = min(res, nums[i] - nums[i - 1] + 1);
//         }
//         return res;
//     }

//     int minimumCardPickup(vector<int>& cards) {
//         int n = cards.size();
//         if(n < 2) return -1;
//         // 值与下标位置对应
//         unordered_map<int, vector<int>> mp;
//         for(int i = 0; i < n; ++i)
//         {
//             mp[cards[i]].push_back(i);
//         }
//         vector<int> dp(n, INT_MAX);
//         int res = INT_MAX;
//         for(int i = 0; i < n; ++i)
//         {
//             res = min(res, distance(mp[cards[i]]));
//         }
//         return res == INT_MAX? -1: res;
//     }
// };

// int main()
// {
//     vector<int> cards = {3,4,2,3,4,7};
//     return 0;
// }



// 周赛第三题
// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     int countDistinct(vector<int>& nums, int k, int p) {
//         // 哈希表存储可被p整除的数字
//         unordered_set<int> dic;
//         for(int num: nums)
//         {
//             if(num % p == 0)
//             {
//                 dic.emplace(num);
//             }
//         }
//         int n = nums.size();
//         unordered_set<string> subArray;
//         int res = 0;
//         for(int i = 0; i < n; ++i)
//         {
//             //vector<int> subVec;
//             string subVec = "";
//             int cnt = k;
//             for(int j = i; j < n; ++j)
//             {
//                 if(dic.count(nums[j]) != 0)
//                 {
//                     if(cnt > 0) --cnt;
//                     else break;
//                 }
//                 //subVec.emplace_back(nums[j]);
//                 subVec += to_string(nums[j]) + ",";
//                 subArray.emplace(subVec);
//             }
//         }
//         return subArray.size();
//     }
// };

// int main()
// {
//     vector<int> nums = {2,3,3,2,2};
//     int k = 2, p = 2;
//     Solution solution;
//     int res= solution.countDistinct(nums, k, p);
//     cout << res << endl;
//     return 0;
// }



// 周赛第四题
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int help(string &s, int left, int right)
    {

    }

    long long appealSum(string s) {
        long long res = 0;
        int len = s.length();
        if(len < 2) return 1;
        int subLen = 1;
        for(int i = 0; i < len; ++i)
        {
            for(int j = i; j < len; ++j)
            {

            }
        }
    }
};

int main()
{
    string s = "abbca";
    Solution solution;
    long long res = solution.appealSum(s);
    cout << res << endl;
    return 0;
}