/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A)
    {
        int sum = std::accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0)
        {
            return false;
        }
        sum /= 3;
        int i = 0, j = A.size() - 1;
        int left = 0, right = 0;
        while (i < j)
        {
            if (left != sum)
            {
                left += A[i];
                i++;
            }
            if (right != sum)
            {
                right += A[j];
                --j;
            }
            if (left == sum && right == sum)
            {
                return true;
            }
        }
        return false;
    }
};

// √ Accepted
//   √ 53/53 cases passed (60 ms)
//   √ Your runtime beats 97.91 % of cpp submissions
//   √ Your memory usage beats 15.18 % of cpp submissions (12.7 MB)