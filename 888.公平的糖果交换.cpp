/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int suma = accumulate(A.begin(), A.end(), 0);
        int sumb = accumulate(B.begin(), B.end(), 0);
        int offset = (suma - sumb) / 2;
        for (auto a : A)
        {
            int tmp = a - offset;
            if (std::find(B.begin(), B.end(), tmp) != B.end())
            {
                return {a, tmp};
            }
        }
        return {0, 0};
    }
};

// √ Accepted
//   √ 75/75 cases passed (960 ms)
//   √ Your runtime beats 32.89 % of cpp submissions
//   √ Your memory usage beats 94.74 % of cpp submissions (12 MB)