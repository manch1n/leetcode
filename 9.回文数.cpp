/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (56.11%)
 * Total Accepted:    89.4K
 * Total Submissions: 159.3K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

using namespace std;
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<=9) return true;
        string num=to_string(x);
        int i=0,j=num.size()-1;
        for(;i<j;i++,j--)
        {
            if(num[i]!=num[j]) return false;
        }
        return true;
    }
};


// √ Accepted
//   √ 11509/11509 cases passed (72 ms)
//   √ Your runtime beats 98.39 % of cpp submissions
//   √ Your memory usage beats 93.02 % of cpp submissions (8.1 MB)