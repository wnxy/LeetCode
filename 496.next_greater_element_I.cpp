/**
 * @file 496.next_greater_element_I.cpp
 * @author your name (you@domain.com)
 * @brief 下一个更大的元素 I
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;    // nums2中每个元素的下一个更大元素
        stack<int> stk;
        for(int i = 0; i < nums2.size(); ++i) {
            while(!stk.empty() && stk.top() < nums2[i]) {
                dict[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        while(!stk.empty()) {
            dict[stk.top()] = -1;
            stk.pop();
        }

        /*for(int a: tmp) {
            cout << a << " ";
        }
        cout << endl;*/
        vector<int> res(nums1.size());    // nums1中的每个元素的下一个最大的元素
        for(int i = 0; i < nums1.size(); ++i) {
            res[i] = dict[nums1[i]];
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution solution;
    vector<int> res = solution.nextGreaterElement(nums1, nums2);
    return 0;
}