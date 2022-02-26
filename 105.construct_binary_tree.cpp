/**
 * @file 105.construct_binary_tree.cpp
 * @author your name (you@domain.com)
 * @brief 从前序和中序遍历序列构造二叉树
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

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

class Solution {
public:
    //递归构造二叉树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = nullptr;
        if(preorder.size() <= 0) return root;
        root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int len = it - inorder.begin();
        vector<int> preleft(preorder.begin() + 1, preorder.begin() + len + 1);
        vector<int> inleft(inorder.begin(), it);
        vector<int> prerigth(preorder.begin() + len + 1, preorder.end());
        vector<int> inright(it + 1, inorder.end());
        root->left = buildTree(preleft, inleft);
        root->right = buildTree(prerigth, inright);
        return root;
    }
};

class Solution1 {
public:
    //递归构造二叉树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if(len == 0) return nullptr;
        return constructTree(preorder, inorder, 0, len - 1, 0, len - 1);
    }

    TreeNode* constructTree(vector<int>& pre, vector<int>& in, int preleft, int preright, int inleft, int inright)
    {
        if(preright < preleft || inright < inleft) return nullptr;
        TreeNode *root = new TreeNode(pre[preleft]);
        int rootin = inleft;
        while(in[rootin] != pre[preleft]) ++rootin;
        int left = rootin - inleft;
        root->left = constructTree(pre, in, preleft + 1, preleft + left, inleft, rootin - 1);
        root->right = constructTree(pre, in, preleft + left + 1, preright, rootin + 1, inright);
        return root;
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
    Solution solution;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    printTreeVal(solution.buildTree(preorder, inorder));
    return 0;
}