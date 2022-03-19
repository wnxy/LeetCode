#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int start = 1, digit = 1;
        long count = 9;
        // 确定n所在的数位数有几位
        while(n - count > 0)
        {
            n -= count;
            start *= 10;    
            ++digit;
            count = 9 * start * digit;
        }
        //确定n所在的数是？
        long num = start + (n - 1) / digit;
        int res = to_string(num).at((n - 1) % digit) - '0';
        return res;
    }
};

int main()
{
    int n = 1000000000;
    Solution solution;
    cout << solution.findNthDigit(n) << endl;
    return 0;
}