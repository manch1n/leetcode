/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */
#include <string>
using namespace std;
class Solution
{
public:
    inline bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        else
            return false;
    }
    string toGoatLatin(string S)
    {
        auto i = S.begin();
        auto j = S.begin();
        string result;
        string append = "a";
        while (1)
        {
            while (i != S.end() && !isalpha(*i))
            {
                ++i;
            }
            j = i;
            while (j != S.end() && isalpha(*j))
            {
                ++j;
            }
            string tmp(i, j);
            i = j;
            if (isVowel(tolower(tmp[0])))
            {
            }
            else
            {
                char c = tmp[0];
                tmp.erase(tmp.begin());
                tmp.insert(tmp.end(), c);
            }
            tmp += "ma";
            tmp += append;
            append.insert(append.end(), 'a');
            result += tmp;
            if (j == S.end())
            {
                break;
            }
            result += " ";
        }
        return result;
    }
};

// √ Accepted
//   √ 99/99 cases passed (8 ms)
//   √ Your runtime beats 68.91 % of cpp submissions
//   √ Your memory usage beats 81.52 % of cpp submissions (9.1 MB)