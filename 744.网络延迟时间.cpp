/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 网络延迟时间
 */

#include <vector>
using namespace std;
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        for (auto c : letters)
        {
            if (c > target)
            {
                return c;
            }
        }
        return letters[0];
    }
};

// √ Accepted
//   √ 165/165 cases passed (12 ms)
//   √ Your runtime beats 96.82 % of cpp submissions
//   √ Your memory usage beats 78.92 % of cpp submissions (9.1 MB)