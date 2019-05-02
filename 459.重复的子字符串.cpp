/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int size = s.size();
        if (size <= 1)
            return false; //when meet the same alpha,try it
        string::iterator q = s.begin() + 1;
        for (; q != s.end();)
        {
            while (q != s.end() && *q != *s.begin())
            {
                q++;
            }
            int diff = q - s.begin();
            if (diff > size / 2)
            {
                return false;
            }
            if (size % diff != 0)
            {
                if (q != s.end())
                {
                    q++;
                }
                continue;
            }
            else
            {
                auto tmp_q = q;
                auto tmp_p = s.begin();
                string t(s.begin(), q);
                bool is_completed = false;
                while (tmp_q != s.end())
                {
                    tmp_p += diff;
                    tmp_q += diff;
                    string s(tmp_p, tmp_q);
                    if (s != t)
                    {
                        is_completed = false;
                        break;
                    }
                    is_completed = true;
                }
                if (is_completed == true)
                {
                    return true;
                }
                q++;
            }
        }
        return false;
    }
};

// √ Accepted
//   √ 120/120 cases passed (48 ms)
//   √ Your runtime beats 73.25 % of cpp submissions
//   √ Your memory usage beats 62.15 % of cpp submissions (15.8 MB)