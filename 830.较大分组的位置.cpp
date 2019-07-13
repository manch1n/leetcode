/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        int size = S.size();
        int i = 0, j = 0;
        int continuous = 0;
        vector<vector<int>> res;
        while (j < size)
        {
            while (j < size && S[j] == S[i])
            {
                continuous++;
                ++j;
            }
            if (continuous >= 3)
            {
                res.push_back({i, j - 1});
            }
            i = j;
            continuous = 0;
        }
        return res;
    }
};

// √ Accepted
//   √ 202/202 cases passed (16 ms)
//   √ Your runtime beats 67.4 % of cpp submissions
//   √ Your memory usage beats 85.71 % of cpp submissions (9.3 MB)
