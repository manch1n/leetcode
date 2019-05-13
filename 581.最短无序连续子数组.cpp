/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int nCount = nums.size();
        int i = 0, j = nCount - 1;
        while (i < j)
        {
            if (nums[i + 1] < nums[i])
                break;
            i++;
        }
        while (j > i)
        {
            if (nums[j - 1] > nums[j])
                break;
            j--;
        }
        if (i == j)
            return 0;
        int nMin = nums[i], nMax = nums[i];
        for (int k = i + 1; k <= j; k++)
        {
            nMin = min(nums[k], nMin);
            nMax = max(nums[k], nMax);
        }
        int flag_i = 0, flag_j = 0;
        while (--i >= 0)
        {
            if (nums[i] <= nMin)
                break;
        }
        while (++j < nCount)
        {
            if (nums[j] >= nMax)
                break;
        }
        return j - i - 1;
    }
};

// √ Accepted
//   √ 307/307 cases passed (48 ms)
//   √ Your runtime beats 82.58 % of cpp submissions
//   √ Your memory usage beats 89.21 % of cpp submissions (10.5 MB)
