/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int countBinarySubstrings(string s)
    {

        int cur = 1, pre = 0, sum = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i])
                cur++;
            else
            {
                sum += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return sum + min(cur, pre);
    }
};
// https://blog.csdn.net/dxx707099957/article/details/82454253
// √ Accepted
//   √ 90/90 cases passed (36 ms)
//   √ Your runtime beats 95 % of cpp submissions
//   √ Your memory usage beats 74.07 % of cpp submissions (12.9 MB)