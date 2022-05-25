/**
 * @file guanglianda.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> pos(n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin >> pos[i];
    }
    if(n == 1) 
    {
        cout << 1 << endl;
        return 0;
    }
    int res = 6;
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; ++i)
    {
        ++mp[pos[i]];
    }
    int min_pos = *min_element(pos.begin() + 1, pos.end());
    int max_pos = *max_element(pos.begin() + 1, pos.end());
    vector<int> dp(max_pos + 1, 0);
    for(int i = min_pos + k; i <= max_pos; ++i)
    {
        for(int j = i; j >= i - k; --j)
        {
            dp[i] += mp[j];
        }
    }
    res = *max_element(dp.begin(), dp.end());
    *max_element(dp.begin(), dp.end()) = 0;
    res += *max_element(dp.begin(), dp.end());
    cout << res << endl;
    return 0;
}