/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 前缀和后缀搜索
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        if (cost.size() == 0)
        {
            return 0;
        }
        if (cost.size() == 1)
        {
            return cost[0];
        }
        if (cost.size() == 2)
        {
            return std::min(cost[0], cost[1]);
        }
        int step[1024];
        step[0] = 0;
        step[1] = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            step[i] = std::min(step[i - 1] + cost[i - 1], step[i - 2] + cost[i - 2]);
        }
        return step[cost.size()];
    }
};

// √ Accepted
//   √ 276 / 276 cases passed(20 ms)
//   √ Your runtime beats 32.04 % of cpp submissions
//   √ Your memory usage beats 82.15 % of cpp submissions(8.8 MB)