/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int size = A.size();
        int i = 0, j = size - 1;
        while (i < j)
        {
            if (A[i] % 2 == 1 && A[j] % 2 == 0)
            {
                int c = A[i];
                A[i] = A[j];
                A[j] = c;
                i++, j--;
            }
            else if (A[i] % 2 == 0)
                i++;
            else if (A[j] % 2 == 1)
                j--;
        }
        return A;
    }
};
// √ Accepted
//   √ 285/285 cases passed (64 ms)
//   √ Your runtime beats 31.82 % of cpp submissions
//   √ Your memory usage beats 87.69 % of cpp submissions (9.6 MB)