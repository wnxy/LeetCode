/**
 * @file leetcode.cpp
 * @author your name (you@domain.com)
 * @brief leetcode 第292场周赛
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// 292周赛第二题

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res = 0;
    vector<int> post;
    // 统计节点和对应的子树和
    unordered_map<TreeNode*, int> mp;
    int dfs(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int lSum = dfs(root->left);
        int rSum = dfs(root->right);
        mp[root] = lSum + rSum + root->val;
        return mp[root];
    }
    
    int Order(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int lCnt = Order(root->left);
        int rCnt = Order(root->right);
        int cnt = lCnt + rCnt + 1;
        mp[root] /= cnt;
        return cnt;
    }
    
    void postOrder(TreeNode* root)
    {
        if(root != nullptr)
        {
            postOrder(root->left);
            postOrder(root->right);
            post.emplace_back(root->val);
            int sum = accumulate(post.begin(), post.end(), 0);
            if(sum / post.size() == root->val)
            {
                ++res;
            }
        }
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        for(auto it = mp.begin(); it != mp.end(); ++it)
        {
            if(it->first->val == it->second)
            {
                ++res;
            }
        }
        return res;
    }
};

class Solution1 {
public:
    unordered_map<TreeNode*, int> mp;
    pair<int, int> dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            return pair{0, 0};
        } 
        pair<int, int>lInfo = dfs(root->left);
        pair<int, int>rInfo = dfs(root->right);
        int sum = lInfo.first + rInfo.first + root->val;
        int cnt = lInfo.second + rInfo.second + 1;
        mp[root] = sum / cnt;
        return pair{sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        dfs(root);
        for(auto it = mp.begin(); it != mp.end(); ++it)
        {
            if(it->first->val == mp[it->first]) ++res;
        }
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    TreeNode *node1 = new TreeNode(8);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(0);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(6);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;

    Solution solution;
    cout << solution.averageOfSubtree(root) << endl;
}