/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */
#include <string>
using namespace std;
class Solution
{
public:
    inline bool isCapital(char c)
    {
        if (c >= 65 && c <= 90)
            return true;
        else
            return false;
    }
    bool detectCapitalUse(string word)
    {
        int size = word.size();
        if (size == 0)
            return false;
        if (size == 1)
            return true;
        if (isCapital(word[0]))
        {
            //all capital case
            if (isCapital(word[1]))
            {
                for (auto c : word)
                {
                    if (!isCapital(c))
                    {
                        return false;
                    }
                }
            }
            //only the first is capital case
            else
            {
                for (int i = 1; i < size; ++i)
                {
                    if (isCapital(word[i]))
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            for (auto &c : word)
            {
                if (isCapital(c))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// √ Accepted
//   √ 550/550 cases passed (8 ms)
//   √ Your runtime beats 99.26 % of cpp submissions
//   √ Your memory usage beats 82.03 % of cpp submissions (8.2 MB)
