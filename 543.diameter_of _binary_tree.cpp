/**
 * @file 543.diameter_of _binary_tree.cpp
 * @author your name (you@domain.com)
 * @brief 二叉树的直径
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using namespace std;

class Solution {
public:
    //求左右子树的最大深度之和
    int ans = 0;
    int depth(TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr) return 0;
        int l = root->left == nullptr? 0: depth(root->left) + 1;
        int r = root->right == nullptr? 0: depth(root->right) + 1;
        ans = max(ans, l + r);
        return max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
};

int main()
{
    return 0;
}