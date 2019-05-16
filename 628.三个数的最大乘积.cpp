/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //找出最大的三个数。2负一正，全都是负数？
    int maximumProduct(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        if (nums[nums.size() - 1] < 0 && nums[nums.size() - 2] < 0 && nums[0] >= 0)
        {
            int max1 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[0];
            int max2 = nums[0] * nums[1] * nums[2];
            return max1 > max2 ? max1 : max2;
        }
        else
            return nums[0] * nums[1] * nums[2];
    }
};

// √ Accepted
//   √ 83/83 cases passed (84 ms)
//   √ Your runtime beats 79.1 % of cpp submissions
//   √ Your memory usage beats 77.08 % of cpp submissions (10.9 MB)