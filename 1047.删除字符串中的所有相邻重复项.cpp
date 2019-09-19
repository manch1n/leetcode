/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string S)
    {
        int delcount = 0;
        do
        {
            delcount = 0;
            for (int i = 0; i < S.size() - 1; ++i)
            {
                if (S[i] == S[i + 1])
                {
                    if (S.size() == 2)
                    {
                        return "";
                    }
                    else
                    {
                        S.erase(S.begin() + i, S.begin() + i + 2);
                        delcount++;
                        break;
                    }
                }
            }
        } while (delcount != 0);
        return S;
    }
};
// √ Accepted
//   √ 98/98 cases passed (360 ms)
//   √ Your runtime beats 27.52 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (11.4 MB)