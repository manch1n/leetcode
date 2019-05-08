/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <string>
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int size = s.size();
        if (k >= size)
        {
            std::reverse(s.begin(), s.end());
            return s;
        }
        int offset = 2 * k;
        for (int i = 0; i < size;)
        {
            if (i + offset <= size)
            {
                std::reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                if (i + k <= size)
                {
                    std::reverse(s.begin() + i, s.begin() + i + k);
                }
                else
                {
                    std::reverse(s.begin() + i, s.end());
                }
                break;
            }
            i += offset;
        }
        return s;
    }
};

// √ Accepted
//   √ 60/60 cases passed (12 ms)
//   √ Your runtime beats 95.96 % of cpp submissions
//   √ Your memory usage beats 77.78 % of cpp submissions (9.6 MB)