/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int K)
    {
        std::sort(A.begin(), A.end());
        int i = 0;
        for (; i < A.size(); ++i)
        {
            if (K-- > 0)
            {
                if (A[i] < 0)
                {
                    A[i] = -A[i];
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        K++;
        if (K == 0 || K % 2 == 0)
        {
            return std::accumulate(A.begin(), A.end(), 0);
        }
        else
        {
            if ((i + 1) == A.size())
            {
                A[i - 1] = -A[i - 1];
            }
            else
            {
                A[i] = -A[i];
            }
            return std::accumulate(A.begin(), A.end(), 0);
        }
    }
};

// √ Accepted
//   √ 78/78 cases passed (8 ms)
//   √ Your runtime beats 91.11 % of cpp submissions
//   √ Your memory usage beats 46.17 % of cpp submissions (8.7 MB)