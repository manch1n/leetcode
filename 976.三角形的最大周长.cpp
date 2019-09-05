/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        int result = 0;
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 2; --i)
        {
            int a = A[i];
            int b = A[i - 1];
            int c = A[i - 2];
            if (a + b > c && a + c > b && b + c > a)
            {
                result = a + b + c;
                break;
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 84/84 cases passed (100 ms)
//   √ Your runtime beats 16.78 % of cpp submissions
//   √ Your memory usage beats 70.26 % of cpp submissions (10.6 MB)