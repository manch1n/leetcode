/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */
#include <string>
using namespace std;
class Solution
{
public:
    inline char upper(char c)
    {
        if (c >= 'a' && c <= 'z')
        {
            return c - 32;
        }
        else
        {
            return c;
        }
    }
    string licenseKeyFormatting(string S, int K)
    {
        int dash_count = 0;
        for (auto c : S)
        {
            if (c == '-')
            {
                ++dash_count;
            }
        }
        int size = S.size();
        int first = (size - dash_count) % K;
        string result;
        int round = 0;
        int i = 0;
        if (first)
        {
            while (first)
            {
                if (S[i] != '-')
                {
                    result.push_back(upper(S[i]));
                    --first;
                }
                ++i;
            }
            result.push_back('-');
        }
        for (; i < size; ++i)
        {
            if (S[i] != '-')
            {
                result.push_back(upper(S[i]));
                round++;
            }
            if (S[i] != '-' && round % K == 0)
            {
                result.push_back('-');
            }
        }
        result.erase(result.end() - 1);
        return result;
    }
};
// √ Accepted
//   √ 38/38 cases passed (20 ms)
//   √ Your runtime beats 86.16 % of cpp submissions
//   √ Your memory usage beats 78.57 % of cpp submissions (10.6 MB)