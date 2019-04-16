/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (43.41%)
 * Total Accepted:    9.2K
 * Total Submissions: 21.2K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */
#include <string>

using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        char map[256] = {0};
        bool is_mapped[256] = {0};
        int size = s.size();
        if (size <= 1)
            return true;
        for (int i = 0; i < size; i++)
        {
            if (map[s[i]] == 0) // &&确保s中的不同字母不能映射同一个t中的字母
            {
                if (is_mapped[t[i]] == false)
                {
                    is_mapped[t[i]] = true;
                }
                else
                {
                    return false;
                }
                map[s[i]] = t[i]; //s->t 映射
            }
            else
            {
                if (map[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// √ Accepted
//   √ 30/30 cases passed (12 ms)
//   √ Your runtime beats 94.87 % of cpp submissions
//   √ Your memory usage beats 57.52 % of cpp submissions (9 MB)