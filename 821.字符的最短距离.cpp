/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> index;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == C)
            {
                index.push_back(i);
            }
        }
        vector<int> result;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == C)
            {
                result.push_back(0);
            }
            else
            {
                int min = INT_MAX;
                for (int j = 0; j < index.size(); ++j)
                {
                    if (abs(i - index[j]) < min)
                    {
                        min = abs(i - index[j]);
                    }
                }
                result.push_back(min);
            }
        }
        return result;
    }
};
// √ Accepted
//   √ 76/76 cases passed (32 ms)
//   √ Your runtime beats 21.36 % of cpp submissions
//   √ Your memory usage beats 74.8 % of cpp submissions (9 MB)