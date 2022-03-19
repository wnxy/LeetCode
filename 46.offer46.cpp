#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string numStr = to_string(num);
        int n = numStr.length();
        int a = 1, b = 1;
        for(int i = 1; i < n; ++i)
        {
            //int tmp = numStr[i] - '0' + (numStr[i - 1] - '0') * 10;
            if(numStr.substr(i - 1, 2) >= "10" && numStr.substr(i - 1, 2) < "26")
            {
                int tmp = b;
                b = b + a;
                a = tmp;
            }
            /*else
            {
                b = b;
            }*/
        }
        return b;
    }
};

int main()
{
    int n = 12256;
    Solution solution;
    cout << solution.translateNum(n) << endl;
    return 0;
}