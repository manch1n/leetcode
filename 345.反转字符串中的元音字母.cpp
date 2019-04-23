/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include <string>
using namespace std;
class Solution
{
public:
    bool is_vovel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s)
    {
        int size = s.size();
        if (size <= 1)
            return s;
        //a e i o u
        int i = 0, j = size - 1;
        while (i < j)
        {
            while (!is_vovel(s[i]) && i < j)
                ++i;
            while (!is_vovel(s[j]) && i < j)
                --j;
            if (i < j)
            {
                std::swap(s[i], s[j]);
                ++i, --j;
            }
        }
        return s;
    }
};


// √ Accepted
//   √ 481/481 cases passed (16 ms)
//   √ Your runtime beats 94.7 % of cpp submissions
//   √ Your memory usage beats 42.59 % of cpp submissions (9.9 MB)