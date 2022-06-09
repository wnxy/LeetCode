/**
 * @file 220.contains_duplicate_III.cpp
 * @author your name (you@domain.com)
 * @brief 存在重复元素 III
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    using ll = long long;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty())
        {
            return false;
        }
        set<ll> st;
        for(int i = 0; i < nums.size(); ++i)
        {
            ll tmp = (ll)nums[i] - (ll)t;
            auto it = st.lower_bound(tmp);
            ll tmp1 = (ll)nums[i] + (ll)t;
            if(it != st.end() && *it <= nums[i] + t)
            {
                return true;
            }
            st.insert(nums[i]);
            if(i >= k)
            {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};

class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        set<long> st;
        for (int i = 0; i < nums.size(); i++) 
        {
            //long tmp = (long)nums[i] - t;
            auto lb = st.lower_bound((long)nums[i] - t);
            if (lb != st.end() && *lb <= (long)nums[i] + t) 
                return 1;
            st.insert(nums[i]);
            if (i >= k) 
                st.erase(nums[i - k]);
        }
        return 0;
    }
};


int main()
{
    vector<int> nums = {-2147483640,-2147483641};

    int k = 1, t = 100;
    Solution solution;
    cout << solution.containsNearbyAlmostDuplicate(nums, k, t) << endl;
    return 0;
}