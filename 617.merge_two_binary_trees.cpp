/**
 * @file 617.merge_two_binary_trees.cpp
 * @author your name (you@domain.com)
 * @brief 合并两颗二叉树
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <queue>

struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

/**
 * @brief DFS实现二叉树合并
 * 
 */
class Solution {
public:
    //递归实现
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        TreeNode *ans = new TreeNode();
        ans->val = root1->val + root2->val;
        ans->left = mergeTrees(root1->left, root2->left);
        ans->right = mergeTrees(root1->right, root2->right);
        return ans;
    }
};

/**
 * @brief BFS实现二叉树合并
 * 
 */
class Solution1 {
public:
    //BFS实现
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr) 
            return root1 == nullptr?root2:root1;
        std::queue<TreeNode *> merge_q;
        std::queue<TreeNode *> quene1;
        std::queue<TreeNode *> quene2;
        auto merged = new TreeNode(root1->val + root2->val);
        merge_q.push(merged);
        quene1.push(root1);
        quene2.push(root2);
        while(!quene1.empty() && !quene2.empty())
        {
            auto node1 = quene1.front();
            auto node2 = quene2.front();
            auto node = merge_q.front();
            quene1.pop();
            quene2.pop();
            merge_q.pop();
            if(node1->left != nullptr || node2->left != nullptr)
            {
                if(node1->left != nullptr && node2->left != nullptr)
                {
                    quene1.push(node1->left);
                    quene2.push(node2->left);
                    auto left = new TreeNode(node1->left->val + node2->left->val);
                    node->left = left;
                    merge_q.push(node->left);
                }
                else if(node1->left != nullptr && node2->left == nullptr)
                {
                    //quene1.push(node1->left);
                    node->left = node1->left;
                }
                else
                {
                    //quene2.push(node2->left);
                    node->left = node2->left;
                }
            }
            if(node1->right != nullptr || node2->right != nullptr)
            {
                if(node1->right != nullptr && node2->right != nullptr)
                {
                    quene1.push(node1->right);
                    quene2.push(node2->right);
                    auto right = new TreeNode(node1->right->val + node2->right->val);
                    node->right = right;
                    merge_q.push(node->right);
                }
                else if(node1->right != nullptr && node2->right == nullptr)
                {
                    //quene1.push(node1->right);
                    node->right = node1->right;
                }
                else
                {
                    //quene2.push(node2->right);
                    node->right = node2->right;
                }
            }
            
        }
        return merged;
    }
};

/**
 * @brief BFS遍历二叉树并输出其节点值
 * 
 * @param root 
 */
void printTreeVal(TreeNode *root)
{
    if(root == nullptr) 
        std::cout << "null" << std::endl;
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        /* code */
        auto node = q.front();

        std::cout << node->val << " ";
        q.pop();
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
    std::cout << std::endl;
}

int main()
{
    Solution1 solution;
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    auto node11 = new TreeNode(3);
    auto node12 = new TreeNode(5);
    auto node13 = new TreeNode(2);
    node11->left = node12;
    root1->left = node11;
    root1->right = node13;

    auto node21 = new TreeNode(1);
    auto node22 = new TreeNode(3);
    auto node23 = new TreeNode(4);
    auto node24 = new TreeNode(7);
    node21->right = node23;
    node22->right = node24;
    root2->left = node21;
    root2->right = node22;
    auto merged = solution.mergeTrees(root1, root2);

    printTreeVal(root1);
    std::cout << std::endl;
    printTreeVal(root2);
    std::cout << std::endl;

    printTreeVal(merged);
    std::cout << std::endl;
    //std::cout << 1 << std::endl;
    return 0;
}