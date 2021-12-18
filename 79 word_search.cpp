#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //dfs搜索网格中每一个字符为起点的结果
    bool dfs(vector<vector<char>> &board, vector<vector<int>> &tag, string &word, int i, int j, int loc)
    {
        if(loc == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) 
        {
            return false;
        }
        if(board[i][j] != word[loc]) return false;
        if(tag[i][j] == 0)
        {
            tag[i][j] = 1;
            if(dfs(board, tag, word, i-1, j, loc+1) ||
            dfs(board, tag, word, i+1, j, loc+1) ||
            dfs(board, tag, word, i, j-1, loc+1) ||
            dfs(board, tag, word, i, j+1, loc+1))
            {
                return true;
            }
            tag[i][j] = 0;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty()) return false;
        int row = board.size(), col = board[0].size();
        vector<vector<int>> tag(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(dfs(board, tag, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution solution;
    if(solution.exist(board, "ABCCED"))
    {
        cout << "exist!" << endl;
    }
    else
    {
        cout << "Not exist!" << endl;
    }
    return 0;
}