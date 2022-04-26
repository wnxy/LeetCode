/**
 * @file 82.remove_duplicates_from_sorted_list_II.cpp
 * @author your name (you@domain.com)
 * @brief 删除排序链表中的重复元素
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode();
        unordered_map<int, int> dic;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            ++dic[cur->val];
            cur = cur->next;
        }
        cur = dummy;
        for(auto it: dic)
        {
            if(it.second == 1)
            {
                cur->next = new ListNode(it.first);
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

ListNode* arrayToList(vector<int>& nums)
{
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    for(const int& num: nums)
    {
        ListNode* node = new ListNode(num);
        cur->next = node;
        cur = cur->next;
    }
    return dummy->next;
}

int main()
{
    vector<int> nums = {1,2,3,3,4,4,5};
    ListNode* head = arrayToList(nums);
    Solution solution;
    head = solution.deleteDuplicates(head);
    return 0;
}