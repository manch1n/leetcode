/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */
#include <string>
#include <set>
using namespace std;
class Solution
{
public:
    inline bool is_alpha(char c)
    {
        if (c == ' ')
            return false;
        else
            return true;
    }
    int countSegments(string s)
    {
        if (s.size() == 0)
            return 0;
        int count = 0;
        for (auto i = s.begin(), j = s.begin(); i != s.end() && j != s.end();)
        {
            while (is_alpha(*j) && j != s.end())
            {
                ++j;
            }
            if (i != j)
            {
                count++;
            }
            while (!is_alpha(*j) && j != s.end())
            {
                ++j;
            }
            i = j;
        }
        return count;
    }
};

// √ Accepted
//   √ 26/26 cases passed (8 ms)
//   √ Your runtime beats 95.51 % of cpp submissions
//   √ Your memory usage beats 61.65 % of cpp submissions (8.4 MB)
