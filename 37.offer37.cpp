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
        if(root == nullptr) return "";
        string res = "";
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
           if(node != nullptr)
           {
               res.append(to_string(node->val)).append(sep);
               q.push(node->left);
               q.push(node->right);
           }
           else
           {
               res.append(invalid).append(sep);
           }
        }
        cout << "res = " << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<string> nodes = split(data, sep);
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode* > q;
        q.push(root);
        for(int i = 1; i < data.length();)
        {
            auto node = q.front();
            q.pop();
            string left = nodes[i++];
            if(left != invalid)
            {
                node->left = new TreeNode(stoi(left));
                q.push(node->left);
            }
            else
            {
                node->left = nullptr;
            }
            string right = nodes[i++];
            if(right != invalid)
            {
                node->right = new TreeNode(stoi(right));
                q.push(node->right);
            }
            else
            {
                node->right = nullptr;
            }
        }
        return root;
    }

private:
    vector<string> split(const string& str, const string& pattern)
    {
        if(str.empty()) return {};
        string strs = str;
        //if(str.back() != pattern.back()) strs.append(pattern);
        vector<string> res;
        auto pos = strs.find(pattern);
        while(pos != strs.npos)   // 查找成功
        {
            string tmp = strs.substr(0, pos);
            res.emplace_back(tmp);
            strs = strs.substr(pos + 1, strs.length());
            pos = strs.find(pattern);
        }
        return res;
    }

private:
    string invalid = "#", sep = ",";
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    string str = "1,2,3,#,#,4,5,#,#,#,#,";
    Codec codec;
    TreeNode *root = codec.deserialize(str);
    return 0;
}