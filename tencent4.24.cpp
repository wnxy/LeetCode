/**
 * @file tencent4.24.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// 腾讯笔试第一题
/*
input:
3
0123
1234
2345
output:
12 123 234 345
*/
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool compare(const string& s1, const string& s2)
// {
//     if(s1.size() == s2.size())
//     {
//         return s1 < s2;
//     }
//     return s1.size() < s2.size();
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<string> vec(n);
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> vec[i];
//     }
//     vector<string> res;
//     int strLen = vec[0].size();
//     for(int j = 0; j < strLen; ++j)
//     {
//         string strNum = "";
//         bool flag = false;
//         for(int i = 0; i < n; ++i)
//         {
//             if(!flag && vec[i][j] == '0')
//             {
//                 continue;
//             }
//             else
//             {
//                 flag = true;
//                 strNum += vec[i][j];
//             }
//         }
//         if(strNum.empty())
//         {
//             res.push_back("0");
//         }
//         else
//         {
//             res.emplace_back(strNum);
//         }
//     }
//     sort(res.begin(), res.end(), compare);
//     for(int i = 0; i < res.size(); ++i)
//     {
//         cout << res[i] << " ";
//     }
//     return 0;
// }



// 腾讯笔试第二题
/*
input:
[1,2,3,4]
output:
3
*/
#include <iostream>
#include <vector>
//#include <list>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a int整型vector 
     * @return int整型
     */
    int getNumber(vector<int>& a) {
        // write code here
        
        while(a.size() > 1)
        {
            int n = a.size();
            for(int i = 0; i < n; ++i)
            {
                if(!help(i + 1))
                {
                    a.erase(a.begin() + i);
                }
            }
        }
        
        return a[0];
    }
    // 判断数是不是质数
    bool help(int num)
    {
        if(num == 1) return false;
        int a = num / 2;
        for(int i = 2; i <= a; ++i)
        {
            if(num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution solution;
    cout << solution.getNumber(nums) << endl;
}


// 腾讯笔试第三题
/*
input:
4
0011
output:
1
*/
// #include <iostream>
// #include <string>
// #include <vector>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// // 0进攻，1防守
// // 第一进攻，第二防守
// int main()
// {
//     int n = 0; 
//     cin >> n;
//     vector<char> vec(n);
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> vec[i];
//     }
//     vector<int> dp1(n + 1);  // 表示左边的进攻力量总和
//     dp1[0] = 0;
//     vector<int> dp2(n + 1);  // 表示右边的防守力量总和
//     dp2[n] = 0;
//     for(int pos = 1; pos <= n; ++pos)
//     {
//         if(vec[pos - 1] == '0')
//         {
//             dp1[pos] = dp1[pos - 1] + pos;
//         }
//         else
//         {
//             dp1[pos] = dp1[pos - 1];
//         }
//     }
//     for(int pos = n - 1; pos >= 0; --pos)
//     {
//         if(vec[pos] == '1')
//         {
//             dp2[pos] = dp2[pos + 1] + pos + 1;
//         }
//         else
//         {
//             dp2[pos] = dp2[pos + 1];
//         }
//     }
//     int res = INT_MAX;
//     for(int pos = 0; pos <= n; ++pos)
//     {
//         res = min(abs(dp1[pos] - dp2[pos]), res);
//     }
//     cout << res << endl;
//     return 0;
// }




// 腾讯笔试第五题，股票问题
/*
input:
6 2
2 3 1 1 1 2
output:
6
*/
// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> prices(n);
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> prices[i];
//     }
//     int res = 0;

//     // 维护单调递减栈
//     stack<int> stk;
//     int num = 0, count = m;   // num表示当前拥有的股票数量，count表示资产金额
//     for(int i = 0; i < n; ++i)
//     {
//         while(!stk.empty() && prices[i] > stk.top())
//         {
//             if(num > 0)
//             {
//                 count += prices[i];
//                 --num;
//             }
//             stk.pop();
//         }
//         if(count >= prices[i])
//         {
//             stk.push(prices[i]);
//             count -= prices[i];
//             ++num;
//         }
//     }
//     if(stk.size() == n) res = m;
//     else
//     {
//         res = count + num * stk.top();
//     }
//     cout << res << endl;
//     return 0;
// }