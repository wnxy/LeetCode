// 网易校招第二题
/*
4 3 2
2 5 3 4

4
*/
// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int n, p, x;
//     cin >> n >> p >> x;
//     vector<int> nums(n);
//     int sum = 0;
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> nums[i];
//         sum += nums[i];
//     }
//     int res = 0;
//     if(sum % x == 0)
//     {
//         for(int num: nums)
//         {
//             int idx = p;
//             for(int i = 1; i <= p; i += x)
//             {
//                 if((sum - num + i) % x == 0 && i != num)
//                 {
//                     ++res;
//                 }
//             }
//         }
//     }
//     else
//     {
//         for(int num: nums)
//         {
//             int idx = x - (sum % x);
//             for(int i = 1; i <= p; i += idx)
//             {
//                 if((sum - num + i) % x == 0 && i != num)
//                 {
//                     ++res;
//                 }
//             }
//         }
//     }
//     cout << res << endl;
//     return 0;
// }


// 网易校招第三题
/*
4 3
1 2 2
1 3 4
2 3 6

-1
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cin >> edges[i][j];
        }
    }
    int res = -1;
    for(const auto& info: edges)
    {
        if(info[0] == 1 && info[1] == n)
        {
            res = info[2];
        }
        else if(info[0] == n && info[1] == 1)
        {
            res = info[2];
        }
    }
    cout << res << endl;
    return 0;
}