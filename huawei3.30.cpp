/**
 * @file huawei3.30.cpp
 * @author your name (you@domain.com)
 * @brief 华为2022/3/30春季实习机试
 * @version 0.1
 * @date 2022-03-31
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
    华为2022/3/30机考第二题
    求图中两个点之间的最短路径的距离和最短路径的条数
*/
// P2 100%
// 5 5
// 0 1
// 3 3
// 1
// 2 2
// output: 4 5
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int m, n, startx, starty, endx, endy, c, tmp1, tmp2, mindistance, npath;
// const vector<vector<int>> direct = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// /**
//  * @brief 图的遍历，寻找两点之间的最短距离
//  * 
//  * @param map 地图
//  * @param vis 标志此点是否被访问
//  * @param dis 此时路径的距离
//  * @param i 开始访问的行
//  * @param j 开始访问的列
//  */
// void dfs(vector<vector<int>>& map, vector<vector<int>>& vis, int dis, int i, int j)
// {
//     if(i == endx && j == endy)
//     {
//         if(mindistance > dis)
//         {
//             mindistance = dis;
//             npath = 1;
//         }
//         else if(mindistance == dis)
//         {
//             ++npath;
//         }
//         return;
//     }
//     if(mindistance == dis)
//     {
//         return;
//     }
//     for(int k = 0; k < 4; ++k)
//     {
//         int dx = i + direct[k][0];
//         int dy = j + direct[k][1];
//         if(dx >= 0 && dx < m && dy >= 0 && dy < n && map[dx][dy] == 0 && vis[dx][dy] == 0)
//         {
//             vis[dx][dy] = 1;
//             dfs(map, vis, dis + 1, dx, dy);
//             vis[dx][dy] = 0;
//         }
//     }
// }

// int main() 
// {
//     cin >> m >> n >> startx >> starty >> endx >> endy >> c;
//     vector<vector<int>> map(m, vector<int>(n, 0));
//     vector<vector<int>> vis(m, vector<int>(n, 0));
//     mindistance = m + n;
//     npath = 0;
//     while(c--)
//     {
//         cin >> tmp1 >> tmp2;
//         map[tmp1][tmp2] = 1;     // 表示高山湖泊
//     }
//     dfs(map, vis, 0, startx, starty);
//     cout << npath << endl << mindistance << endl;
//     system("pause");
//     return 0;
// }


/*
    华为2022/3/30机考第三题
    求解相同的最大子树，以层序遍历序列的方式给定一个二叉树，寻找树中相同的两个最大子树，只有一个节点的不算
*/
// input [1,2,3,1,null,2,null,null,null,1,null,null,null]
// output [2,1,null]
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {} 
};

/**
 * @brief 字符串分割
 * 
 * @param str 
 * @param c 
 * @return vector<string> 
 */
vector<string> splitStr(string& str, char c)
{
    if(str.empty()) return {};
    vector<string> res;
    int pos = 0, start = 0;
    while(pos < str.size())
    {
        pos = str.find(c, start);
        if(pos != str.npos)
        {
            res.emplace_back(str.substr(start, pos - start));
            start = pos + 1;
        }
    }
    return res;
}

/**
 * @brief 前序遍历序列化二叉树+哈希表判断重复子树
 * 
 * @param root 
 * @param res 
 * @param umap 
 * @return string 
 */
string dfs(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& umap)
{
    if(root == nullptr) return "#,";
    string serial = to_string(root->val) + "," + dfs(root->left, res, umap) + dfs(root->right, res, umap);
    if(umap[serial] == 1)
    {
        if(root->left != nullptr || root->right != nullptr)
        {
            res.emplace_back(root);
        }
    }
    umap[serial]++;
    return serial;
}

/**
 * @brief 寻找给定树的相同子树
 * 
 * @param root 
 * @return TreeNode* 
 */
TreeNode* equalSubTree(TreeNode* root)
{
    if(root == nullptr) return nullptr;
    vector<TreeNode*> res;
    unordered_map<string, int> umap;
    dfs(root, res, umap);
    return res[0];
}

/**
 * @brief 根据层序遍历的结果构建一颗二叉树
 * 
 * @param s 
 * @return TreeNode* 
 */
TreeNode* deSerialTree(string &s)
{
    if(s.empty()) return nullptr;
    vector<string> seq = splitStr(s, ',');
    TreeNode* root = new TreeNode(stoi(seq[0]));
    queue<TreeNode*> q;
    q.push(root);
    for(int i = 1; i < seq.size(); )
    {
        auto node = q.front();
        q.pop();
        string left = seq[i];
        if(left != "null")
        {
            node->left = new TreeNode(stoi(left));
            q.push(node->left);
        }
        else
        {
            node->left = nullptr;
        }
        ++i;
        string right = seq[i];
        if(right != "null")
        {
            node->right = new TreeNode(stoi(right));
            q.push(node->right);
        }
        else
        {
            node->right = nullptr;
        }
        ++i;
    }
    return root;
}

/**
 * @brief 层序遍历打印树的节点
 * 
 * @param root 
 */
void printTree(TreeNode* root)
{
    cout << "[";
    vector<string> level;
    if(root == nullptr)
    {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        if(node != nullptr)
        {
            level.emplace_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            level.emplace_back("null");
        }
    }
    level.pop_back();   // 去掉末尾序列中的两个空节点
    level.pop_back();   // 去掉末尾序列中的两个空节点
    for(int i = 0; i < level.size(); ++i)
    {
        cout << level[i];
        if(i != level.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main()
{
    string str;
    cin >> str;
    str.pop_back();    // 去掉末尾']'
    str = str.substr(1, str.length());    // 去掉开始'['
    str.push_back(',');
    TreeNode* root = deSerialTree(str);

    printTree(equalSubTree(root));

    return 0;
}

// P2 100%
// 5 5
// 0 1
// 3 3
// 1
// 2 2
// output: 4 5
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// int minDis, nPath = 0;
// int m, n, startx, starty, endx, endy, g, t1, t2;
// const vector<vector<int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// void dfs(const vector<vector<int>> &e, vector<vector<bool>> &vis, int dis, int x, int y)
// {
//     if (x == endx && y == endy)
//     {
//         if (minDis > dis)
//         {
//             minDis = dis;
//             nPath = 1;
//         }
//         else if (minDis == dis)
//             nPath++;
//         return;
//     }
//     if (dis == minDis)
//         return;
//     vis[x][y] = 1;
//     dis++;
//     for (int i = 0; i < 4; i++)
//     {
//         int dx = x + d[i][0], dy = y + d[i][1];
//         if (dx >= 0 && dx < m && dy >= 0 && dy < n && e[dx][dy] == 0 && vis[dx][dy] == 0)
//         {
//             dfs(e, vis, dis, dx, dy);
//         }
//     }
//     vis[x][y] = 0;
// }

// int main()
// {
//     cin >> m >> n >> startx >> starty >> endx >> endy >> g;
//     vector<vector<int>> e(m, vector<int>(n, 0));
//     vector<vector<bool>> vis(m, vector<bool>(n, 0));
//     while (g--)
//     {
//         cin >> t1 >> t2;
//         e[t1][t2] = 1;
//     }
//     minDis = m + n;
//     dfs(e, vis, 0, startx, starty);
//     cout << nPath << " " << minDis;
//     system("pause");
//     return 0;
// }