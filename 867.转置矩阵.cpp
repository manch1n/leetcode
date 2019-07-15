/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {

        int m = A.size();
        int n = A[0].size();
        vector<int> B(m, 0);
        vector<vector<int>> C(n, B);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                C[j][i] = A[i][j];
        }
        return C;
    }
};

// √ Accepted
//   √ 36/36 cases passed (40 ms)
//   √ Your runtime beats 66.96 % of cpp submissions
//   √ Your memory usage beats 97.7 % of cpp submissions (11.3 MB)