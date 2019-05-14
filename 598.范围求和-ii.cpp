/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        if (ops.size() == 0)
            return m * n;
        int mina = ops[0][0];
        int minb = ops[0][1];
        for (int i = 1; i < ops.size(); i++)
        {
            mina = min(mina, ops[i][0]);
            minb = min(minb, ops[i][1]);
        }
        return mina * minb;
    }
};

// √ Accepted
//   √ 69/69 cases passed (32 ms)
//   √ Your runtime beats 33.33 % of cpp submissions
//   √ Your memory usage beats 77.91 % of cpp submissions (11.6 MB)