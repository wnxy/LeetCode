/*
* 单词拆封
*/
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
        for(const string &word : wordDict)
        {
            string cur_s(s);
            auto it = cur_s.find(word);
            //要么第一个单词，要么最后一个单词
            if((it != s.npos) && (it == 0 || it == cur_s.length()-word.length()))
            {
                cur_s.erase(it, word.length());
                if(wordBreak(cur_s, wordDict))
                {
                    return true;
                }
            }
        }
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
    Solution solution;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict  = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << solution.wordBreak(s, wordDict) << endl;
    return 0;
}
