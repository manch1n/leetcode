/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <vector>
#include <algorithm>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        for (auto &n : A)
        {
            n = n * n;
        }
        std::sort(A.begin(), A.end());
        return A;
    }
};

// √ Accepted
//   √ 132/132 cases passed (308 ms)
//   √ Your runtime beats 5.85 % of cpp submissions
//   √ Your memory usage beats 85.53 % of cpp submissions (13.5 MB)