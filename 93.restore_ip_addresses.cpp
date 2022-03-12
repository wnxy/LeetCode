/**
 * @file 93.restore_ip_addresses.cpp
 * @author your name (you@domain.com)
 * @brief 复原IP地址
 * @version 0.1
 * @date 2022-03-11
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
    vector<string> res;

    //中止递归的条件：ip地址分了4段，并且字符串已被瓜分完了
    void backTrack(string& s, vector<string>& track, int begin, int len)
    {
        if(begin == len)
        {
            if(track.size() == 4)
            {
                //增加一种答案
                string ans = track[0];
                for(int i = 1; i < 4; ++i)
                {
                    ans += "." + track[i];     
                }
                res.emplace_back(ans);
            }
            return;
        }
        if(track.size() > 4) return;
        if(begin > len) return;
        for(int l = 1; l < 4; ++l)
        {
            if(begin + l > len) return;
            string tmp = s.substr(begin, l);
            //排除0x, 0xx, 00x等情况
            if(l > 1 && tmp[0] == '0')
            {
                return;
            }
            if(stoi(tmp) > 255) return;
            track.push_back(tmp);
            backTrack(s, track, begin + l, len);
            track.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if(len < 4 || len > 12) return res;
        vector<string> track;
        backTrack(s, track, 0, len);
        return res;
    }
};

int main()
{
    Solution solution;
    string ip = "101023";
    vector<string> res = solution.restoreIpAddresses(ip);
    for(string str : res)
    {
        cout << str << endl;
    }
    cout << endl;
    return 0;
}