/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        int be = 0;
        int left = 0;
        string result;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == '(')
            {
                left++;
            }
            else
            {
                left--;
            }
            if (left == 0)
            {
                result += string(S.begin() + be + 1, S.begin() + i);
                be = i + 1;
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 59/59 cases passed (12 ms)
//   √ Your runtime beats 33.38 % of cpp submissions
//   √ Your memory usage beats 55.29 % of cpp submissions (9 MB)