/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    inline int layer(char c)
    {
        if (c == 'q' || c == 'w' || c == 'e' || c == 'r' || c == 't' || c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'p')
        {
            return 0;
        }
        else if (c == 'a' || c == 's' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || c == 'j' || c == 'k' || c == 'l')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    inline char lower(char c)
    {
        if (c >= 65 && c <= 90)
        {
            return c + 32;
        }
        else
            return c;
    }
    vector<string> findWords(vector<string> &words)
    {
        vector<string> result;
        for (auto &s : words)
        {
            int current = layer(lower(s[0]));
            bool flag = true;
            for (auto c : s)
            {
                if (layer(lower(c)) != current)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                result.push_back(s);
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 22/22 cases passed (8 ms)
//   √ Your runtime beats 95.3 % of cpp submissions
//   √ Your memory usage beats 53.62 % of cpp submissions (8.6 MB)