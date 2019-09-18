/*
 * @lc app=leetcode.cn id=1033 lang=cpp
 *
 * [1033] 移动石子直到连续
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> stones({a, b, c});
        std::sort(stones.begin(), stones.end());
        int min = 0, max = 0;
        for (int i = 1; i < 3; ++i)
        {
            if (stones[i - 1] + 1 != stones[i])
            {
                min += 1;
                max += stones[i] - stones[i - 1] - 1;
            }
        }
        if (stones[1] - stones[0] == 2 || stones[2] - stones[1] == 2)
        {
            min = 1;
        }
        return {min, max};
    }
};
// √ Accepted
//   √ 187/187 cases passed (8 ms)
//   √ Your runtime beats 26.48 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (8.1 MB)
