/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词模式
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (38.31%)
 * Total Accepted:    6.4K
 * Total Submissions: 16.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。
 * 
 * 这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

#include <string>
#include <map>
#include <sstream>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        int size = pattern.size();
        if (size == 0)
            return false;
        map<string, char> str_map;
        istringstream s{str};
        string p;
        bool is_mapped[26]{0};
        int i = 0;
        while (s >> p)
        {
            if (str_map.count(p))
            {
                if (pattern[i] != str_map[p])
                    return false;
            }
            else
            {
                if (is_mapped[pattern[i] - 97])
                    return false;
                str_map[p] = pattern[i];
                is_mapped[pattern[i] - 97] = true;
            }
            i++;
        }
        if (i != size)
            return false;
        return true;
    }
};

// √ Accepted
//   √ 33/33 cases passed (8 ms)
//   √ Your runtime beats 94.05 % of cpp submissions
//   √ Your memory usage beats 30.95 % of cpp submissions (8.6 MB)
