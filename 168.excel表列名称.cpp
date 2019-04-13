/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (31.14%)
 * Total Accepted:    6.7K
 * Total Submissions: 21.5K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */

#include <string>
using namespace std;

class Solution
{
public:
    string convertToTitle(int n)
    {
        string str;
        if (n <= 26)
        {
            char c = n + 64;
            return string{c};
        }
        int carry = 0;
        //0A 1B 3C...25Z  ascii 65
        while (n)
        {
            int c = n % 26 + 64;
            if (carry)
            {
                c -= carry;
                carry = 0;
            }
            if (c <= 64)
            {
                carry = 65 - c;
                str.insert(str.begin(), 'Z');
                n /= 26;
                continue;
            }
            str.insert(str.begin(), c);
            n = n / 26;
        }
        if (carry)
            str.erase(str.begin());
        return str;
    }
};

// √ Accepted
//   √ 18/18 cases passed (4 ms)
//   √ Your runtime beats 96.77 % of cpp submissions
//   √ Your memory usage beats 74.86 % of cpp submissions (8 MB)