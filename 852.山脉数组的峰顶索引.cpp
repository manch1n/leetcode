/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */
#include <vector>
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &A)
    {
        for (int i = 1; i < A.size(); ++i)
        {
            if (A[i] < A[i - 1])
            {
                return i - 1;
            }
        }
        return 0;
    }
};

// √ Accepted
//   √ 32/32 cases passed (16 ms)
//   √ Your runtime beats 91.1 % of cpp submissions
//   √ Your memory usage beats 73.97 % of cpp submissions (9.4 MB)