/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        int size = A.size();
        if (size <= 1)
        {
            return true;
        }
        int flag;
        for (int i = 1; i < size; ++i)
        {
            if (A[i] != A[i - 1])
            {
                flag = A[i] - A[i - 1];
                break;
            }
        }
        if (flag >= 0)
        {
            for (int i = 1; i < size; ++i)
            {
                if (A[i] - A[i - 1] < 0)
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 1; i < size; ++i)
            {
                if (A[i] - A[i - 1] > 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// √ Accepted
//   √ 366/366 cases passed (84 ms)
//   √ Your runtime beats 74.29 % of cpp submissions
//   √ Your memory usage beats 86.24 % of cpp submissions (13.9 MB)