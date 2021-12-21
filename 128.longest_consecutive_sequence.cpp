/*
* 最长连续序列
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        unordered_set<int> nums_set;
        for(const int &num : nums)
        {
            nums_set.emplace(num);
        }
        int cur_num, cur_count = 1, longest_count = 0;
        for(const int &num : nums_set)
        {
            if(!nums_set.count(num - 1))
            {
                cur_num = num;
                while(nums_set.count(cur_num + 1))
                {
                    ++cur_count;
                    ++cur_num;
                }
            }
            longest_count = max(cur_count, longest_count);
            cur_count = 1;
        }
        return longest_count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,2,0,1};
    cout << solution.longestConsecutive(nums) << endl;
    return 0;
}