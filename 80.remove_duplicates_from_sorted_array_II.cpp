/**
 * @file 80.remove_duplicates_from_sorted_array_II.cpp
 * @author your name (you@domain.com)
 * @brief 删除有序数组中的重复项
 * @version 0.1
 * @date 2022-06-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
        {
            return n;
        }
        int slow = 2, fast = 2;
        while(fast < n)
        {
            if(nums[fast] != nums[fast - 2])
            {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        return slow;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution solution;
    int res = solution.removeDuplicates(nums);
    for(int i = 0; i < res; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}