/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 *
 * https://leetcode-cn.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (62.79%)
 * Total Accepted:    13K
 * Total Submissions: 20.6K
 * Testcase Example:  '38'
 *
 * 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
 * 
 * 示例:
 * 
 * 输入: 38
 * 输出: 2 
 * 解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
 * 
 * 
 * 进阶:
 * 你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
 * 
 */
class Solution
{
public:
    int addDigits(int num)
    {
        int next = 0;
        while (num >= 10)
        {
            while (num)
            {
                next += num % 10;
                num /= 10;
            }
            num = next;
            next = 0;
        }
        return num;
    }
};

// √ Accepted
//   √ 1101/1101 cases passed (12 ms)
//   √ Your runtime beats 92.55 % of cpp submissions
//   √ Your memory usage beats 53.22 % of cpp submissions (8.1 MB)