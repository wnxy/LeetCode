/**
 * @file leetcode_weekly_contest_295.cpp
 * @author your name (you@domain.com)
 * @brief leetcode第295场周赛
 * @version 0.1
 * @date 2022-05-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     unordered_map<char, int> dic1;
//     unordered_map<char, int> dic2;
//     int target_dp[26] = {0};
//     int s_dp[26] = {0};
    
//     int rearrangeCharacters(string s, string target) {
//         for(char c: target)
//         {
//             ++target_dp[c - 'a'];
//         }
//         for(char c: s)
//         {
//             ++s_dp[c - 'a'];
//         }
//         int res = s.size();
//         for(int i = 0; i < target.size(); ++i)
//         {
//             res = min(res, (int)(s_dp[target[i] - 'a'] / target_dp[target[i] - 'a']));
//         }
//         return res;
//     }
// };

// int main()
// {
//     string s = "ilovecodingonleetcode";
//     string target = "code";
//     Solution solution;
//     cout << solution.rearrangeCharacters(s, target) << endl;
//     return 0;
// }



//Line 1034: Char 34: runtime error: addition of unsigned offset to 0x603000000070 overflowed to 0x602faf756070 (stl_v
//[4,5,7,7,13]
//[10,1,2,3,4,5,6,1,2,3]


#include <iostream>
#include <string>
using namespace std;
 
class Solution {
public:
    string helper(string str, int discount)
    {
        string res = "$", tmp = "";
        for(int i = 1; i < str.size(); ++i)
        {
            if(str[i] < '0' || str[i] > '9')
            {
                return "";
            }
            tmp += str[i];
        }
        if(tmp.empty()) return "";
        double price = stod(tmp);
        price -= price * discount / 100;
        string tt = to_string(price);
        int loc = tt.find('.', 0);
        res += tt.substr(0, loc + 1);
        string post = "00";
        if(loc + 1 < tt.size()) post[0] = tt[loc + 1];
        if(loc + 2 < tt.size()) post[1] = tt[loc + 2];
        return res + post;
    }

    string discountPrices(string sentence, int discount) {
        string res = "";
        for(int i = 0; i < sentence.size(); )
        {
            if((i == 0 && sentence[i] == '$') || (i > 0 && sentence[i] == '$' && sentence[i - 1] == ' '))
            {
                int loc = sentence.find(' ', i);
                string tmp = sentence.substr(i, loc - i);
                string tt = helper(tmp, discount);
                if(tt.empty())
                {
                    res += tmp;
                }
                else
                {
                    res += tt;
                }
                i += loc - i;
            }
            else
            {
                res += sentence[i];
                ++i;
            }    
        }
        return res;
    }
};

int main()
{
    string sentence = "there are $1 $2 and 5$ candies in the shop";
    string sentence1 = "1 2 $3 4 $5 $6 7 8$ $9 $10$";
    string sentence2 = "ka3caz4837h6ada4 r1 $602";
    string sentence3 = "$76111 ab $6 $";
    int discount = 48;
    Solution solution;
    cout << solution.discountPrices(sentence3, discount) << endl;
    return 0;
}