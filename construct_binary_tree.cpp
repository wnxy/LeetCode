/**
 * @file construct_binary_tree.cpp
 * @author your name (you@domain.com)
 * @brief ACM模式中二叉树的构建
 * @version 0.1
 * @date 2022-03-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
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
};

/**
 * @brief 二叉树构建
 *
 * @param nums
 * @return TreeNode*
 */
TreeNode *constructBinaryTree(const vector<int> &nums)
{
    if (nums.size() == 0)
        return nullptr;
    vector<TreeNode *> vec;
    TreeNode *root = nullptr;
    // 第一次遍历，构建节点
    for (int i = 0; i < nums.size(); ++i)
    {
        TreeNode *node = nullptr;
        if (nums[i] != -1)
        {
            node = new TreeNode(nums[i]);
        }
        vec.emplace_back(node);
        if (i == 0)
            root = node;
    }
    // 第二次遍历，构建二叉树
    for (int i = 0; i * 2 + 2 < nums.size(); ++i)
    {
        if (vec[i] != nullptr)
        {
            vec[i]->left = vec[i * 2 + 1];
            vec[i]->right = vec[i * 2 + 2];
        }
    }
    return root;
}

/**
 * @brief 层序遍历二叉树
 *
 * @param root
 */
void printLevelTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> tmp;
        for (int i = q.size(); i > 0; --i)
        {
            auto node = q.front();
            q.pop();
            tmp.emplace_back(node->val);
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        res.emplace_back(tmp);
    }
    for (int i = 0; i < res.size(); ++i)
    {
        for (int n : res[i])
        {
            cout << n << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> nums = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
    TreeNode *root = constructBinaryTree(nums);
    printLevelTree(root);
    return 0;
}
