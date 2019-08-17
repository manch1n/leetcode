/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int p = 0, q = S.size() - 1;
        while (p < q)
        {
            while (!isalpha(S[p]))
            {
                ++p;
            }
            while (!isalpha(S[q]))
            {
                --q;
            }
            if (p < q)
            {
                std::swap(S[p], S[q]);
            }
            ++p;
            --q;
        }
        return S;
    }
};

// √ Accepted
//   √ 116/116 cases passed (8 ms)
//   √ Your runtime beats 31.29 % of cpp submissions
//   √ Your memory usage beats 90.13 % of cpp submissions (8.2 MB)