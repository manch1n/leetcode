/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (29.16%)
 * Total Accepted:    21.9K
 * Total Submissions: 75K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */
#include <string>
using namespace std;

class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        int i = 0, j = 0;
        int len = s.size();
        i = len - 1;
        j = len - 1;
        while (s[j] == ' ')
        {
            j--;
            i--;
        }
        for (; j >= 0; j--)
        {
            if (s[j] == ' ')
                break;
        }
        return i - j;
    }
};

// √ Accepted
//   √ 59/59 cases passed (12 ms)
//   √ Your runtime beats 12.57 % of cpp submissions
//   √ Your memory usage beats 0.82 % of cpp submissions (8.6 MB)