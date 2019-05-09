/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

#include <string>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        int size = s.size();
        auto i = s.begin();
        auto j = s.begin();
        while (j != s.end())
        {
            while (*j != ' ' && j != s.end())
            {
                ++j;
            }
            std::reverse(i, j);
            if (j == s.end())
            {
                break;
            }
            ++j;
            i = j;
        }
        return s;
    }
};

// √ Accepted
//   √ 30/30 cases passed (32 ms)
//   √ Your runtime beats 70.7 % of cpp submissions
//   √ Your memory usage beats 87.5 % of cpp submissions (11.7 MB)