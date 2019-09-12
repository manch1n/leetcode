/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        std::sort(costs.begin(), costs.end(), [](vector<int> &left, vector<int> &right) {
            return (left[1] - left[0]) > (right[1] - right[0]);
        });
        int sum = 0;
        for (int i = 0; i < costs.size(); ++i)
        {
            if (i < costs.size() / 2)
            {
                sum += costs[i][0];
            }
            else
            {
                sum += costs[i][1];
            }
        }
        return sum;
    }
};

// √ Accepted
//   √ 49/49 cases passed (8 ms)
//   √ Your runtime beats 82.39 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (9.1 MB)