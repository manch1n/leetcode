/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (39.58%)
 * Total Accepted:    21.9K
 * Total Submissions: 55.3K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2:
 * 
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 */

#include <vector>
using namespace std;
class Solution
{
public:
    //emmmmm 刚看过的最大化拿金钱问题，动态规划
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        // vector<int> vec(nums.size() + 1);
        // vec[0] = 0;
        // vec[1] = nums[0];
        // int size = nums.size();
        // for (int i = 2; i <= size; i++)
        // {
        //     int current = vec[i - 2] + nums[i - 1];
        //     vec[i] = current > vec[i - 1] ? current : vec[i - 1];
        // }
        // return vec[size];
        //应该可以使用O（1）的空间复杂度。
        vector<int> vec(3);
        vec[0] = 0;
        vec[1] = nums[0];
        int size = nums.size();
        for (int i = 2; i <= size; i++)
        {
            int current = vec[(i - 2) % 3] + nums[i - 1];
            vec[i % 3] = current > vec[(i - 1) % 3] ? current : vec[(i - 1) % 3];
        }
        return vec[size % 3];
    }
};
/*! 感觉leetcode的空间效率判断有点不精确 */
// √ Accepted
//   √ 69/69 cases passed (8 ms)
//   √ Your runtime beats 95.06 % of cpp submissions
//   √ Your memory usage beats 96.88 % of cpp submissions (8.4 MB)

// √ Accepted
//   √ 69/69 cases passed (8 ms)
//   √ Your runtime beats 95.06 % of cpp submissions
//   √ Your memory usage beats 81.12 % of cpp submissions (8.6 MB)