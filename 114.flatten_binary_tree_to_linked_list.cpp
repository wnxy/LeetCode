/**
 * @file 114.flatten_binary_tree_to_linked_list.cpp
 * @author your name (you@domain.com)
 * @brief 二叉树展开为链表（只有右子树的链表）
 * @version 0.1
 * @date 2022-02-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printBinaryValueBFS(TreeNode *root);

class Solution {
public:
    //先序遍历重建二叉树
    queue<TreeNode *> q;
    void preOrder(TreeNode* root)
    {
        if(root == nullptr) return;
        q.push(root);
        preOrder(root->left);
        preOrder(root->right);
    }

    void createTree(TreeNode *root)
    {
        if(q.empty()) return;
        root->right = q.front();
        root->left = nullptr;
        q.pop();
        createTree(root->right);
    }

    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        preOrder(root);
        root = nullptr;
        root = q.front();
        q.pop();
        createTree(root);
        printBinaryValueBFS(root);
    }
};

class Solution1 {
public:
    //迭代实现二叉树先序遍历
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        auto node = root;
        stack<TreeNode *> s;
        queue<TreeNode *> q;
        while(node != nullptr || !s.empty())
        {
            if(node != nullptr)
            {
                q.push(node);        //队列存储二叉树访问结果
                s.push(node);        //栈存储节点回溯顺序
                node = node->left;
            }
            else
            {
                node = s.top();
                s.pop();
                node = node->right;
            }
        }
        root = nullptr;
        root = q.front();
        q.pop();
        while(!q.empty())
        {
            root->right = q.front();
            root->left = nullptr;
            q.pop();
            root = root->right;
        }
    }
};

class Solution2 {
public:
    //迭代先序遍历二叉树的同时进行二叉树的重建
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        auto node = root;
        root = nullptr;
        stack<TreeNode *> s;
        while(node != nullptr || !s.empty())
        {
            if(node != nullptr)
            {        
                if(root == nullptr)
                {
                    root = node;
                }
                else
                {
                    root->right = node;
                    root->left = nullptr;
                    root = root->right;
                }
                s.push(node);        //栈存储节点回溯顺序
                node = node->left;
            }
            else
            {
                node = s.top();
                s.pop();
                node = node->right;
            }
        }
    }
};

void printBinaryValueBFS(TreeNode *root)
{
    queue<TreeNode *>q;
    if(root == nullptr)
    {
        cout << "null" << " ";
    }
    q.push(root);
    while (!q.empty())
    {
        /* code */
        auto node = q.front();
        q.pop();
        cout << node->val << " ";
        if(node->left)
        {
            q.push(node->left);
        }
        if(node->right)
        {
            q.push(node->right);
        }
    }
    cout << endl;
}

int main()
{
    Solution2 solution;
    TreeNode *root = new TreeNode(1);
    auto node1 = new TreeNode(2);
    auto node2 = new TreeNode(3);
    auto node3 = new TreeNode(4);
    auto node4 = new TreeNode(5);
    auto node5 = new TreeNode(6);
    node1->left = node2;
    node1->right = node3;
    node4->right = node5;
    root->left = node1;
    root->right = node4;
    //printBinaryValueBFS(root);
    solution.flatten(root);
    //printBinaryValueBFS(solution.tmpRoot);
    return 0;
}
