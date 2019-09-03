/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &A)
    {
        int imax = A.size(), jmax = A[0].size();
        int result = 0;
        for (int j = 0; j < jmax; ++j)
            for (int i = 1; i < imax; ++i)
            {
                if (A[i][j] < A[i - 1][j])
                {
                    result++;
                    break;
                }
            }
        return result;
    }
};

// √ Accepted
//   √ 84/84 cases passed (60 ms)
//   √ Your runtime beats 70.2 % of cpp submissions
//   √ Your memory usage beats 89.57 % of cpp submissions (12.9 MB)