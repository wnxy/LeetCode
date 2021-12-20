/*
* 最长连续序列
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_count = 1, len = nums.size();
        if(len < 2) return len;
        sort(nums.begin(), nums.end());
        int tmp_count = 1;
        for(int i = 1; i < len; ++i)
        {
            if(nums[i] == nums[i-1] + 1)
            {
                ++tmp_count;
            }
            else
            {
                max_count = (tmp_count > max_count?tmp_count:max_count);
                tmp_count = 1;
            }
        }
        
        return max_count > tmp_count?max_count:tmp_count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,2,0,1};
    cout << solution.longestConsecutive(nums) << endl;
    return 0;
}