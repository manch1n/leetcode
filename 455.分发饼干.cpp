/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int sizeg = g.size();
        int sizes = s.size();
        if (sizes == 0)
            return 0;
        std::sort(g.begin(), g.end()); //O(nlog(n))
        std::sort(s.begin(), s.end());

        int satisfied = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size();)
        {
            if (s[j] >= g[i])
            {
                ++i;
                ++j;
                ++satisfied;
            }
            else if (s[j] < g[i])
            {
                ++j;
            }
        }
        return satisfied;
    }
};
s
// √ Accepted
//   √ 21/21 cases passed (52 ms)
//   √ Your runtime beats 94.09 % of cpp submissions
//   √ Your memory usage beats 15.54 % of cpp submissions (10.5 MB)