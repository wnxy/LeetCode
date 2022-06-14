// 拼多多笔试题
// 第一题 多多的队列
/*
input:
6
10 8 5 3 50 45

output:
3 2 1 0 1 0
*/
// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> nums[i];
//     }
//     vector<int> res(n, n);
//     stack<int> stk;
//     for(int i = 0; i < n; ++i)
//     {
//         while(!stk.empty() && nums[stk.top()] < nums[i])
//         {
//             res[stk.top()] = i;
//             stk.pop();
//         }
//         stk.push(i);
//     }
//     for(int i = 0; i < n; ++i)
//     {
//         res[i] = res[i] - i - 1;
//         cout << res[i] << " ";
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> nums[i];
//     }
//     vector<int> res(n, n);
//     for(int i = 0; i < n; ++i)
//     {
//         int idx = i;
//         for(int j = i; j < n; ++j)
//         {
//             if(nums[idx] < nums[i])
//             {
//                 idx = j;
//             }
//         }
//         res[i] = idx;
//     }
//     for(int i = 0; i < n; ++i)
//     {
//         //res[i] = res[i] - i - 1;
//         cout << res[i] << " ";
//     }
//     return 0;
// }

// 第二题 搭积木
// #include <iostream>
// #include <vector>
// #include <string>
// #include <set>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;

// bool compare(vector<int>& lhs, vector<int>& rhs)
// {
//     if(!lhs.empty() && !rhs.empty())
//     {
//         return lhs.back() > rhs.back();
//     }
//     return false;
// }

// string helper(int n, int m, vector<vector<int>>& heap)
// {
//     int cnt = 0;
//     sort(heap.begin(), heap.end(), compare);
//     for(int i = 1; i < m; ++i)
//     {
//         if(heap[i].back() == heap[i - 1].back())
//         {
//             heap[i].pop_back();
//             heap[i - 1].pop_back();
//             sort(heap.begin(), heap.end(), compare);
//             cnt += 2;
//         }
//     }
//     if(cnt == 2 * n)
//     {
//         return "yes";
//     }
//     return "no";
// }

// int main()
// {
//     int T;
//     cin >> T;
//     for(int i = 0; i < T; ++i)
//     {
//         int n, m;
//         cin >> n >> m;
//         //unordered_map<int, vector<int>> dic;
//         vector<vector<int>> heap;
//         for(int j = 0; j < m; ++j)
//         {
//             int cnt;
//             cin >> cnt;
//             vector<int> tmp(cnt);
//             for(int k = 0; k < cnt; ++k)
//             {
//                 cin >> tmp[k];
//             }
//             heap.emplace_back(tmp);
//         }
//         cout << helper(n, m, heap) << endl;
//     }
//     return 0;
// }

// 第三题
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <numeric>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     int idx_0 = -1; // 空椅子的开始位置
//     int idx_1 = -1; // 有人的椅子的开始位置
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> nums[i];
//         if (idx_0 == -1 && nums[i] == 0)
//         {
//             idx_0 = i;
//         }
//         if (idx_1 == -1 && nums[i] == 1)
//         {
//             idx_1 = i;
//         }
//     }
//     int res = 0;
//     for (int i = idx_1; i < n; ++i)
//     {
//         if (nums[i] == 1)
//         {
//             int loc = i;
//             int left = i;
//             while (left >= 0)
//             {
//                 if (nums[left] == 0)
//                 {
//                     break;
//                 }
//                 --left;
//             }
//             int right = i;
//             while (right < n)
//             {
//                 if (nums[right] == 0)
//                 {
//                     break;
//                 }
//                 ++right;
//             }
//             if (left < 0)
//                 loc = right;
//             else if (right >= n)
//                 loc = left;
//             else if(abs(left - i) == abs(right - i))
//             {
//                 loc = left;
//             }
//             else
//             {
//                 loc = abs(left - i) > abs(right - i)? right: left;
//             }
//             res += abs(i - loc);
//             nums[i] = 2;
//             nums[loc] = 2;
//         }
//     }
//     cout << res << endl;
//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();
    int res = 0;
    
    for(int i = -(n - 1); i < n; ++i)
    {
        for(int j = -(n - 1); j < n; ++j)
        {
            int tmp = 0;
            for(int ii = 0; ii < n; ++ii)
            {
                for(int jj = 0; jj < n; ++jj)
                {
                    int dx = ii + i, dy = jj + j;
                    if(dx >= 0 && dx < n && dy >= 0 && dy < n)
                    {
                        if(A[ii][jj] && B[dx][dy])
                        {
                            ++tmp;
                        }
                    }
                }
            }
            res = max(res, tmp);
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> A = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 0}
    };
    vector<vector<int>> B = {
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1}
    };
    cout << solution(A, B) << endl;
    return 0;
}