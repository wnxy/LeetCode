// 美团笔试第一题
/*给出一行仅包含空格和小写英文字母的字符串s。其中空格代表被吸走的字符，小写英文字母则是没有被吸走，留下来的字符。

s的长度<=10000

输出仅包含一个正整数，表示黑洞吸走的字母数量
*/
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main()
// {
//     string s;
//     getline(cin, s);
//     int res = 0;
//     for(const char& c: s)
//     {
//         if(c == ' ')
//         {
//             ++res;
//         }
//     }
//     cout << res << endl;
//     return 0;
// }



// 美团笔试第二题
/*第一行给出2个数h1和m1，表示当前时刻的时针数和分针数。

第二行给出2个数h2和m2，表示下午茶时刻的时针数和分针数。

0<=h1,h2<24     0<=m1,m2<60

保证第二个时刻（h2,m2）晚于第一个时刻（h1,m1），且都在同一天。

输出一行一个整数表示还要多少分钟才能从第一个时刻到达第二个时刻（下午茶时间）。 
*/
// #include <iostream>
// using namespace std;

// int main()
// {
//     int h1, m1, h2, m2;
//     cin >> h1 >> m1;
//     cin >> h2 >> m2;
//     // res代表答案，space_h表示间隔时间，space_m表示间隔分钟
//     int res = 0, space_h, space_m;
//     space_h = h2 - h1;
//     space_m = m2 - m1;
//     res = space_h * 60 + space_m;
//     cout << res << endl;
//     return 0;
// }



// 美团笔试第三题
/*
第一行两个正整数n和m，分别表示商品数量以及优惠券种类数。

第二行m个数 L[1,2,…m]，L[i]表示第 i 种优惠券的参数中的 l 值

第三行m个数 R[1,2,…m]，R[i]表示第 i 种优惠券的参数中的 r 值

数字间两两有空格隔开

可能存在两种优惠券参数相同，仍然算作两种。

n,m<=100000

1<=L[i],R[i]<=n

输出一行一个整数表示有多少种商品可以用至少两种优惠券进行优惠。

input:
5 3
1 2 3
2 3 5

output
2
*/
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> l(m, 0);
//     vector<int> r(m, 0);
//     for(int i = 0; i < m; ++i)
//     {
//         cin >> l[i];
//     }
//     for(int i = 0; i < m; ++i)
//     {
//         cin >> r[i];
//     }
//     int res = 0;
//     unordered_map<int, int> dic;
//     for(int i = 0; i < m; ++i)
//     {
//         for(int j = l[i]; j <= r[i]; ++j)
//         {
//             ++dic[j];
//         }
//     }
//     for(int i = 1; i <= n; ++i)
//     {
//         if(dic[i] >= 2)
//         {
//             ++res;
//         }
//     }
//     cout << res << endl;
//     return 0;
// }



// 美团笔试第四题
/*
你是魔法学院中的一个学生。你在魔法课中因老师讲得无聊开始了开小差。你手中有两个数字A和B，你可以释放以下三种魔法：

①选择一个数字，让它变成原先的二倍，即，假如数字本来为n，释放此魔法后将变成2*n 。

②选择一个数字，让它变成原来的一半后向下取整，即，假如数字本来为n，释放此魔法后将变成n/2（向下取整），例：对4释放将变成2，对7释放将变成3（向下取整了）。

③选择一个数字，让它变成原来的值加一，即，加入数字本来为n，释放此魔法后将变成n+1.

 

这三种魔法你都可以任意次数使用，但你是追求完美的学生，你想用尽可能少的释放魔法次数让这两个数变得相等。

第一行两个空格隔开的正整数A和B表示待操作的数。

A<=1000,B<=1000

输出一行，表示让这两个数变得相等需要的最少操作次数。

input:
5 24
output:
3
*/
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main()
// {
//     int A, B;
//     cin >> A >> B;
//     int res = 0;
//     int tmp1 = min(A, B);
//     int tmp2 = max(A, B);
//     vector<int> vec(tmp2 + 1, 0);
//     for(int i = tmp1; i <= tmp2; ++i)
//     {
//         vec[i] = i;
//     }
//     int maxDistance = 0;
//     bool tag = false;
//     for(int i = tmp1; i <= tmp2; ++i)
//     {
//         int dis1 = i + 1;   // 魔法增加1
//         int dis2 = i * 2;   // 魔法乘2
//         maxDistance = max(dis1, dis2);
//         if(tag == false)
//         {
//             ++res;
//             for(int j = i + 1; j <= tmp2;)
//             {
//                 dis1 = j + 1;
//                 dis2 = j * 2;
//                 int tmp = max(dis1, dis2);
//                 maxDistance = max(maxDistance, tmp);
//                 ++res;
//                 j += maxDistance;
//                 if(j >= tmp2)
//                 {
//                     tag = true;
//                     break;
//                 }
//             }
//         }
//     }
//     cout << res << endl;
//     return 0;
// }



// 美团笔试第五题
/*
第一行一个正整数n表示节点个数。

第二行n-1个正整数p[2,3,…n], p[i]表示第 i 个节点的父亲。1号节点是根节点。

第三行n个正整数c[1,2,…n]，c[i]表示第 i 个节点的权值。 

第四行一个正整数m表示询问次数。

第五行m个正整数u[1,2,…m]，u[i]表示第 i 次询问中指定的第一个点。

第六行m个正整数v[1,2,…m]，v[i]表示第 i 次询问中指定的第二个点。

数据保证形成合法的树。数字间两两有空格隔开。

n,m<=50000

c[i]<=1000000000，1<=u[i],v[i]<=n

输出一行m个空格隔开的整数，依次对应每次询问的答案。

input:
3
1 1
1 2 3
3
1 1 2
2 3 3

output:
3 2 0
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 表示树中有n个节点，m次询问
    int n, m; 
    cin >> n;
    vector<int> p(n + 1, 0);  // p[i]表示第i个节点的父亲
    for(int i = 2; i <= n; ++i)
    {
        cin >> p[i];
    }
    vector<int> c(n + 1, 0);  // c[i]表示第i个节点的权值
    for(int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    cin >> m;
    vector<int> u(m, 0);    // i 次询问中指定的第一个点
    vector<int> v(m, 0);    // i 次询问中指定的第二个点
    //vector<int> res(m);
    int res = 0;
    for(int i = 0; i < m; ++i)
    {
        int node = v[i];
        while(node >= u[i])
        {
            if(node == v[i])
            {
                res = c[v[i]];
            }
            else
            {
                res ^= c[node];
            }
            node = p[node];
        }
        cout << res << " ";
    }
    return 0;
}
