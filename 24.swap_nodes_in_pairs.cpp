/**
 * @file 24.swap_nodes_in_pairs.cpp
 * @author your name (you@domain.com)
 * @brief 两两交换链表中的节点
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
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

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        deque<ListNode*> dq1;     // 存储奇数节点
        deque<ListNode*> dq2;     // 存储偶数节点
        int count = 1;
        while(head != nullptr)
        {
            if(count % 2 == 1)
            {
                dq1.push_back(head);
            }
            else
            {
                dq2.push_back(head);
            }
            ++count;
            head = head->next;
        }
        ListNode* dummmy = new ListNode();
        ListNode* cur = dummmy;
        while(!dq2.empty() || !dq1.empty())
        {
            if(!dq2.empty())
            {
                cur->next = dq2.front();
                dq2.pop_front();
                cur = cur->next;
            }
            if(!dq1.empty())
            {
                cur->next = dq1.front();
                dq1.pop_front();
                cur = cur->next;
            }
        }
        cur->next = nullptr;
        return dummmy->next;
    }
};

ListNode* creatList(vector<int>& nums)
{
    if(nums.empty()) return nullptr;
    vector<ListNode*> vec;
    for(int i = 0; i < nums.size(); ++i)
    {
        vec.emplace_back(new ListNode(nums[i]));
    }
    for(int i = 1; i < nums.size(); ++i)
    {
        vec[i - 1]->next = vec[i];
    }
    return vec[0];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    ListNode* head = creatList(nums);
    Solution solution;
    head = solution.swapPairs(head);
    return 0;
}