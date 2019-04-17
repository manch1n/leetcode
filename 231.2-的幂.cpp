/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (44.75%)
 * Total Accepted:    16.6K
 * Total Submissions: 37K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 2^0 = 1
 * 
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 2^4 = 16
 * 
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 * 
 */
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        //用回溯法好像会麻烦很多
        long base = 1;
        while (base <= n)
        {
            if (base == n)
                return true;
            base *= 2;
        }
        return false;
    }
};

// √ Accepted
//   √ 1108/1108 cases passed (8 ms)
//   √ Your runtime beats 96.53 % of cpp submissions
//   √ Your memory usage beats 77.28 % of cpp submissions (7.9 MB)