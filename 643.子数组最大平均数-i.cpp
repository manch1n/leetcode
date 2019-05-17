/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include <vector>
using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int size = nums.size();
        if (k > size)
        {
            return 0.0l;
        }
        double max = 0;
        for (int i = 0; i < k; ++i)
        {
            max += nums[i];
        }
        double prev = max;
        for (int i = k; i < nums.size(); ++i)
        {
            prev = prev + nums[i] - nums[i - k];
            if (prev > max)
            {
                max = prev;
            }
        }
        return max / k;
    }
};

// √ Accepted
//   √ 123/123 cases passed (180 ms)
//   √ Your runtime beats 92.58 % of cpp submissions
//   √ Your memory usage beats 71.55 % of cpp submissions (16.8 MB)
