/**
 * @file 24.offer24.cpp
 * @author your name (you@domain.com)
 * @brief 反转链表
 * 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 * @version 0.1
 * @date 2022-02-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* nxt = head;
        ListNode* cur = head->next;
        ListNode* pre;
        while(cur != nullptr)
        {
            pre = cur->next == nullptr? nullptr: cur->next;
            nxt->next = nullptr;
            cur->next = nxt;
            nxt = cur;
            head = cur;
            cur = pre;
        }
        return head;
    }
};

int main()
{
    Solution solution;
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    node1->next = node2;
    head->next = node1;
    ListNode *res = solution.reverseList(head);
    while(res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}