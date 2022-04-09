/**
 * @file 37.offer37.cpp
 * @author your name (you@domain.com)
 * @brief 序列化二叉树
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#,";
        string serial = to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        //cout << serial << endl;
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        queue<string> seq = splitStr(data, ',');
        return deserialize(seq);
    }

    TreeNode* deserialize(queue<string>& s)
    {
        if(s.empty())
        {
            return nullptr;
        }
        string str = s.front();
        s.pop();
        if(str == "#")
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(str));
        root->left = deserialize(s);
        root->right = deserialize(s);
        return root;
    }

    // 以字符c为分隔符分割字符串s
    queue<string> splitStr(string& s, char c)
    {
        if(s.empty()) return {};
        queue<string> res;
        int start = 0, pos = 0;
        while(pos < s.length())
        {
            pos = s.find(c, start);
            if(pos != s.npos)
            {
                res.emplace(s.substr(start, pos - start));
            }
            start = pos + 1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    string str = "1,2,#,#,3,4,#,#,5,#,#,";
    Codec codec;
    TreeNode *root = codec.deserialize(str);
    return 0;
}