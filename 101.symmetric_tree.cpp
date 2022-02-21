/**
 * @file 101.symmetric_tree.cpp
 * @author your name (you@domain.com)
 * @brief 对称二叉树
 * @version 0.1
 * @date 2022-02-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <queue>

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

class Solution {
public:
    //迭代实现
    queue<TreeNode *> q;
    bool isSymmetric(TreeNode* root) {
        return cmp(root->left, root->right);
    }
    
    bool cmp(TreeNode *left, TreeNode *right)
    {
        q.push(left);
        q.push(right);
        while(!q.empty())
        {
            auto node1 = q.front();
            q.pop();
            auto node2 = q.front();
            q.pop();
            if(node1 == nullptr && node2 == nullptr)
            {
                continue;
            }
            if(node1 == nullptr || node2 == nullptr || node1->val != node2->val)
            {
                return false;
            }
            q.push(node1->left);
            q.push(node2->right);

            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};

int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(1);
    auto node1 = new TreeNode(2);
    auto node2 = new TreeNode(3);
    auto node3 = new TreeNode(4);
    auto node4 = new TreeNode(5);
    auto node5 = new TreeNode(6);
    /*node1->left = node2;
    node1->right = node3;
    node4->right = node5;
    root->left = node1;
    root->right = node4;*/
    cout << solution.isSymmetric(root) << endl;
    return 0;
}