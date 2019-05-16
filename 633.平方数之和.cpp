/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int mid = sqrt(c);
        long left = 0;
        long right = mid + 1;
        while (left <= right)
        {
            long tmp = left * left + right * right;
            if (tmp == c)
            {
                return true;
            }
            else if (tmp < c)
            {
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }
        return false;
    }
};

// √ Accepted
//   √ 124/124 cases passed (8 ms)
//   √ Your runtime beats 96.84 % of cpp submissions
//   √ Your memory usage beats 77.5 % of cpp submissions (8.1 MB)
