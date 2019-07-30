/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int x_y = 0;
        int x_z = 0;
        int y_z = 0;
        for (auto &v : grid)
        {
            for (auto n : v)
            {
                if (n != 0)
                {
                    x_y++;
                }
            }
            y_z += *max_element(v.begin(), v.end());
        }
        int ii = grid[0].size();
        int jj = grid.size();
        for (int j = 0; j < jj; ++j)
        {
            int max = 0;
            for (int i = 0; i < ii; ++i)
            {
                max = std::max(grid[i][j], max);
            }
            x_z += max;
        }
        return x_y + x_z + y_z;
    }
};

// √ Accepted
//   √ 90/90 cases passed (12 ms)
//   √ Your runtime beats 78.48 % of cpp submissions
//   √ Your memory usage beats 93.15 % of cpp submissions (9.2 MB)