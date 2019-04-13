/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (63.19%)
 * Total Accepted:    11.7K
 * Total Submissions: 18.5K
 * Testcase Example:  '"A"'
 *
 * 给定一个Excel表格中的列名称，返回其相应的列序号。
 * 
 * 例如，
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: "A"
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: "AB"
 * 输出: 28
 * 
 * 
 * 示例 3:
 * 
 * 输入: "ZY"
 * 输出: 701
 * 
 * 致谢：
 * 特别感谢 @ts 添加此问题并创建所有测试用例。
 * 
 */

#include <string>
using namespace std;

class Solution
{
public: //因为从1开始计数，所以每一位要加1.
    int titleToNumber(string s)
    {
        int size = s.size();
        if (size == 0)
            return 0;
        int carry = 0;
        long base = 1;
        long result = 0;
        //ascii A65 Z90
        for (int i = size - 1; i >= 0; --i)
        {
            int num = s[i] - 64; //-65+1
            if (carry)
            {
                carry = 0;
                num++;
            }
            if (num == 26)
            {
                base *= 26;
                carry = 1;
                continue;
            }
            result += base * num;
            base *= 26;
        }
        if (carry)
            result += base;
        return result;
    }
};

// √ Accepted
//   √ 1000/1000 cases passed (12 ms)
//   √ Your runtime beats 93.13 % of cpp submissions
//   √ Your memory usage beats 37.4 % of cpp submissions (8.2 MB)