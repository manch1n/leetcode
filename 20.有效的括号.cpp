/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.11%)
 * Total Accepted:    59.2K
 * Total Submissions: 159.5K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include <string>
#include <stack>
using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        int len = s.size();
        std::stack<char> brackets;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                brackets.push(s[i]);
            }
            else if (s[i] == '}')
            {
                if (brackets.empty())
                    return false;
                char temp = brackets.top();
                if (temp != '{')
                    return false;
                else
                    brackets.pop();
            }
            else if (s[i] == ')')
            {
                if (brackets.empty())
                    return false;
                char temp = brackets.top();
                if (temp != '(')
                    return false;
                else
                    brackets.pop();
            }
            else if (s[i] == ']')
            {
                if (brackets.empty())
                    return false;
                char temp = brackets.top();
                if (temp != '[')
                    return false;
                else
                    brackets.pop();
            }
        }
        if (brackets.empty())
            return true;
        else
            return false;
    }
};

// √ Accepted
//   √ 76/76 cases passed (12 ms)
//   √ Your runtime beats 13.39 % of cpp submissions
//   √ Your memory usage beats 0.93 % of cpp submissions (8.4 MB)