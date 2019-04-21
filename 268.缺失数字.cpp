/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (49.25%)
 * Total Accepted:    18K
 * Total Submissions: 36.3K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public: //要线性就需要额外数组而不能做到常数。
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size == 0)
            return -1;
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] != i)
                return i;
        }
        return nums[size - 1] + 1;
    }
};

// √ Accepted
//   √ 122/122 cases passed (44 ms)
//   √ Your runtime beats 47.45 % of cpp submissions
//   √ Your memory usage beats 13.29 % of cpp submissions (9.9 MB)