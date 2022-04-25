// 荣耀笔试第一题
/*
11#10

11
*/
// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// unordered_map<char, int> dic;
// void init()
// {
//     int i = 0;
//     for(char c = '0'; c <= '9'; ++c)
//     {
//         dic[c] = i++;
//     }
//     for(char c = 'a'; c <= 'z'; ++c)
//     {
//         dic[c] = i++;
//     }
//     for(char c = 'A'; c <= 'Z'; ++c)
//     {
//         dic[c] = i++;
//     }
//     dic['@'] = i++;
//     dic['_'] = i++;
// }

// /**
//  * @brief 进制数字转换
//  *
//  * @param num 字符串表示的数字
//  * @param base 进制
//  * @return 
//  */
// void num_convert(string num, int base)
// {
//     long long res = 0;
//     int len = num.length();
//     for(int i = 0; i < num.length(); ++i)
//     {
//         if(dic.count(num[i]) > 0 && dic[num[i]] < base)
//         {
//             //int tt = dic[num[i]];
//             res += dic[num[i]] * (int)pow(base, len - 1 - i);
//         }
//         else
//         {
//             cout << "ERROR" << endl;
//             return;
//         }
//     }
//     cout << res << endl;
// }

// int main()
// {
//     string num = "";
//     cin >> num;
//     init();
//     int len = num.length();
//     int loc = num.find('#');
//     // 判断当前数字是否是特定的bash表示法
//     if (loc != num.npos)
//     {
//         int base = stoi(num.substr(0, loc));
//         num_convert(num.substr(loc + 1, len), base);
//     }
//     else
//     {
//         if (len < 2)
//         {
//             if(isdigit(num[0]))
//             {
//                 cout << num[0] - '0' << endl;
//             }
//             else
//             {
//                 cout << "ERROR" << endl;
//             }
//         }
//         else
//         {
//             if (num[0] == '0') // 八进制
//             {
//                 if (num[1] == 'x' || num[1] == 'X') // 十六进制
//                 {
//                     num_convert(num.substr(2, len), 16);
//                 }
//                 else
//                 {
//                     num_convert(num.substr(1, len), 8);
//                 }
//             }
//             else // 十进制
//             {
//                 num_convert(num, 10);
//             }
//         }
//     }
//     return 0;
// }


/*
200 0 200 10 200 50 200 30 200 25

456
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct point
{
    int x;
    int y;
    bool operator< (const point& p1)
    {
        if(x != p1.x)
        {
            return x < p1.x;
        }
        return y < p1.y;
    }
};

/**
 * @brief 两点之间的最短距离
 * 
 * @param p1 
 * @param p2 
 * @return int 
 */
int distance(point &p1, point &p2)
{
    int w = abs(p1.x - p2.x);
    int h = abs(p1.y - p2.y);
    int res = sqrt(w * w + h * h);
    return res;
}

int main()
{
    vector<point> vec(5);
    for(int i = 0; i < 5; ++i)
    {
        cin >> vec[i].x >> vec[i].y;
    }
    sort(vec.begin(), vec.end());
    point tmp = {0, 0}, init = {0, 0};
    int res = 0, i = 0;
    while(i < 5)
    {
        res += distance(tmp, vec[i]);
        tmp = vec[i];
        ++i;
    }
    res += distance(vec[4], init);
    cout << res << endl;
    return 0;
}


// 荣耀第三题
/*
struct RecordList {
    short recordListTotalValue;
    long recordListTotalPrice;
    struct RecordItem recordItem;
};
sizeof(RecordList)
*/
// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// unordered_map<string, int> dic = {
//     {"short", 2},
//     {"long", 4},
//     {"char", 1}
// };

// vector<string> splitStr(string str, char c)
// {
//     vector<string> res;
//     string tmp = "";
//     for(int i = 0; i < str.size(); ++i)
//     {
//         if(str[i] != ' ')
//         {
//             tmp += str[i];
//         }
//         else
//         {
//             if(!tmp.empty())
//             {
//                 res.emplace_back(tmp);
//                 tmp.clear();
//             }
//         }
//     }
//     if(!tmp.empty())
//     {
//         res.emplace_back(tmp);
//         tmp.clear();
//     }
//     return res;
// }

// int main()
// {
//     string input = "";
//     vector<string> vecIn;
//     getline(cin, input);
//     while(input.substr(0, 6) != "sizeof")
//     {
//         if(!input.empty())
//         {
//             vecIn.emplace_back(input);
//             input.clear();
//         }
//         getline(cin, input);
//     }
//     int res = 0;
//     string structName = "";
//     vector<string> formatStr;
//     for(int i = 0; i < vecIn.size() - 2; ++i)
//     {
//         vector<string> tmp = splitStr(vecIn[i], ' ');
//         if(i == 0)
//         {
//             structName = tmp[1];
//         }
//         else
//         {
//             formatStr.emplace_back(tmp[0]);
//         }
//     }
//     for(string info: formatStr)
//     {
//         if(info != structName)
//         {
//             res += dic[info];
//         }
//         else
//         {
//             res = 0;
//             break;
//         }
//     }
//     cout << res << endl;
//     return 0;
// }