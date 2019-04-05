/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (47.24%)
 * Total Accepted:    20.3K
 * Total Submissions: 42.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
#include <string>
using namespace std;

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        int carry_bit = 0;
        if (a.size() > b.size())
        {
            std::swap(a, b);
        }
        int len1 = a.size();
        int len2 = b.size();
        if (!len1)
            return b;
        for (int i = len1 - 1; i >= 0; i--)
        {
            int b_pos=i+len2-len1;
            if (a[i] == '1' && b[b_pos] == '1')
            {
                if (carry_bit)
                {
                }
                else
                {
                    b[b_pos] = '0';
                    carry_bit = 1;
                }
            }
            else if (a[i] == '1' && b[b_pos] == '0')
            {
                if (carry_bit)
                {
                }
                else
                {
                    b[b_pos] = '1';
                }
            }
            else if (a[i] == '0' && b[b_pos] == '1')
            {
                if (carry_bit)
                {
                    b[b_pos] = '0';
                }
                else
                {
                }
            }
            else
            {
                if (carry_bit)
                {
                    carry_bit = 0;
                    b[b_pos] = '1';
                }
                else
                {
                }
            }
        }
        for (int i = len2 - len1 - 1; i >= 0; i--)
        {
            if (b[i] == '1')
            {
                if (carry_bit)
                {
                    b[i] = '0';
                }
                else
                {
                }
            }
            else
            {
                if (carry_bit)
                {
                    b[i] = '1';
                    carry_bit = 0;
                }
                else
                {
                }
            }
        }
        if (carry_bit)
        {
            b.insert(b.begin(), '1');
        }
        return b;
    }
};

// √ Accepted
//   √ 294/294 cases passed (8 ms)
//   √ Your runtime beats 22.15 % of cpp submissions
//   √ Your memory usage beats 0.79 % of cpp submissions (8.5 MB)