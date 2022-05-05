// 腾讯音乐笔试第二题
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Node
{
    TreeNode *node;
    int value;   // 节点权值
    Node(): node(nullptr), value(0) {}
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回值的树节点中val表示节点权值
     * @param root TreeNode类 给定的初始树节点中的val表示节点编号
     * @param op int整型vector<vector<>> op的组成为[[id,v],[id,v],[id,v],...]
     * @return TreeNode类
     */
    // 以层序遍历的方式编号树的节点
    void levelTree(TreeNode* root, unordered_map<int, Node*>& mp)
    {
        if(root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            mp[node->val] = {node, 0};
            if(node->left != nullptr)
            {
                q.push(node->left);
            }
            if(node->right != nullptr)
            {
                q.push(node->right);
            }
        }
    }
    
    // 给定树中的每个节点值异或一个v
    void operate(Node* root, int v)
    {
        if(root->node != nullptr)
        {
            root->value ^= v;
            operate(root->node->left, v);
            operate(root->right, v);
        }
    }
    
    TreeNode* xorTree(TreeNode* root, vector<vector<int> >& op) {
        // write code here
        if(op.empty()) return root;
        unordered_map<int, Node*> mp;
        levelTree(root, mp);
        for(auto p: op)
        {
            operate(mp[p[0]], p[1]);
        }
        return root;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    root->left = node1;
    root->right = node2;
    vector<vector<int>> op = {{2, 4}, {1, 2}};
    Solution solution;
    TreeNode *res = solution.xorTree(root, op);
    return 0;
}