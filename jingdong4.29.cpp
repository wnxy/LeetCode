// 京东笔试第一题
/*

*/
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     if(n < 3 && k < 3)
//     {
//         cout << 0 << endl;
//         return 0;
//     }
//     int res = 0;
//     cout  << res << endl;
//     return 0;
// }



// 京东笔试第二题
/*
input:
5
0 1 1 3 4
1 0 1 3 1
output:
3
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647

struct point
{
    int x;
    int y;
    bool operator < (const point& p)
    {
        if(x != p.x)
        {
            return x < p.x;
        }
        return y < p.y;
    }
};

int distance(point& p1, point& p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int help(point& p, vector<point>& point, int i)
{
    int res = INT_MAX;
    for(int j = i + 1; j < point.size(); ++j)
    {
        res = min(res, distance(p, point[j]));
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<point> point(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> point[i].x;
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> point[i].y;
    }
    sort(point.begin(), point.end());
    int res = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        res = max(res, help(point[i], point, i));
    }
    cout << res << endl;
    return 0;
}