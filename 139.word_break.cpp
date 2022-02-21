/*
 * 单词拆封
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief 动态规划解决单词划分问题
 *
 */
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (s.empty())
            return true;
        unordered_set<string> wordDictSet;
        for (const string &str : wordDict)
        {
            wordDictSet.emplace(str);
        }
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i < s.size() + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

/**
 * @brief DFS+记忆剪枝解决单词划分问题
 *
 */
class Solution1
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordDictSet;
        for (auto str : wordDict)
        {
            wordDictSet.emplace(str);
        }
        vector<int> memory(s.size(), -1);
        return dfs(s, wordDictSet, memory, 0);
    }

    bool dfs(string s, unordered_set<string> &wordDictSet, vector<int> &memo, int start)
    {
        if(start > s.size()-1) return true;
        if(memo[start] != -1) return memo[start];
        for (int end = start + 1; end <= s.size(); ++end)
        {
            if (wordDictSet.find(s.substr(start, end-start)) != wordDictSet.end() && dfs(s, wordDictSet, memo, end))
            {
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = 0;
        return false;
    }
};

/*
* test case
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
*/
int main()
{
    Solution1 solution;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    //string s = "leetcode";
    //vector<string> wordDict = {"leet", "code"};
    cout << solution.wordBreak(s, wordDict) << endl;
    return 0;
}
