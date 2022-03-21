/**
 * @file 23.merge_k_sorted_lists.cpp
 * @author your name (you@domain.com)
 * @brief 合并K个升序链表
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct compare
    {
        bool operator() (const ListNode* node1, const ListNode* node2)
        {
            return node1->val > node2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;  //小顶堆
        for(auto list : lists)
        {
            while(list != nullptr)
            {
                heap.push(list);
                list = list->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(!heap.empty())
        {
            cur->next = heap.top();
            heap.pop();
            cur = cur->next;
            cur->next = nullptr;
        }
        return dummy->next;
    }
};

ListNode* constructList(vector<int>& nums)
{
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    for(auto num : nums)
    {
        ListNode *node = new ListNode(num);
        cur->next = node;
        cur = cur->next;
    }
    return dummy->next;
}

void printListVal(ListNode* l1)
{
    while(l1 != nullptr)
    {
        cout << l1->val << " ";
        l1 = l1->next;
    }
    cout << endl;
}

int main()
{
    vector<ListNode *>lists;
    vector<int> list1 = {1, 4, 5};
    vector<int> list2 = {1, 3, 4};
    vector<int> list3 = {2, 6};
    lists.emplace_back(constructList(list1));
    lists.emplace_back(constructList(list2));
    lists.emplace_back(constructList(list3));
    Solution solution;
    ListNode* res = solution.mergeKLists(lists);
    printListVal(res);
    return 0;
}