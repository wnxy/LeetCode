/**
 * @file 687.longest_univalue_path.cpp
 * @author your name (you@domain.com)
 * @brief 求最长同值操作路径
 * @version 0.1
 * @date 2022-02-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

using namespace std;

/**
 * @brief 二叉树结点定义
 * 
 */
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

class Solution
{
public:
    //本题同543题，124题
    int ans = 0;
    int dfs(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        int lPath = root->left == nullptr ? 0 : dfs(root->left) + 1;
        if ((root->left) && (root->val != root->left->val))
        {
            lPath = 0;
        }
        int rPath = root->right == nullptr ? 0 : dfs(root->right) + 1;
        if ((root->right) && (root->val != root->right->val))
        {
            rPath = 0;
        }
        ans = max(ans, lPath + rPath);
        return max(lPath, rPath);
    }

    int longestUnivaluePath(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        dfs(root);
        return ans;
    }
};

int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(5);
    auto node1 = new TreeNode(4);
    auto node2 = new TreeNode(1);
    auto node3 = new TreeNode(1);
    auto node4 = new TreeNode(5);
    auto node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node4->right = node5;
    root->left = node1;
    root->right = node4;
    cout << solution.longestUnivaluePath(root) << endl;
    return 0;
}