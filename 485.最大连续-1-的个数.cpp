/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */
#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int current = 0;
        int max = 0;
        for (auto n : nums)
        {
            if (n)
            {
                current += 1;
                if (current > max)
                {
                    max = current;
                }
            }
            else
            {
                current = 0;
            }
        }
        return max;
    }
};

// √ Accepted
//   √ 41/41 cases passed (48 ms)
//   √ Your runtime beats 95.19 % of cpp submissions
//   √ Your memory usage beats 51.82 % of cpp submissions (11.8 MB)