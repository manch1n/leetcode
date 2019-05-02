/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */
#include <vector>
using namespace std;
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int result = 0;
        int row = grid.size();
        int column = grid[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int round = 0;
                    if (j > 0)
                    {
                        if (grid[i][j - 1] == 1)
                        {
                            round += 1;
                        }
                    }
                    if (i > 0)
                    {
                        if (grid[i - 1][j] == 1)
                        {
                            round += 1;
                        }
                    }
                    if (j < column - 1)
                    {
                        if (grid[i][j + 1] == 1)
                        {
                            round += 1;
                        }
                    }
                    if (i < row - 1)
                    {
                        if (grid[i + 1][j] == 1)
                        {
                            round += 1;
                        }
                    }
                    result += 4 - round;
                }
            }
        }
        return result;
    }
};

//看不出来这哪里用哈希表了
// √ Accepted
//   √ 5833/5833 cases passed (112 ms)
//   √ Your runtime beats 95.09 % of cpp submissions
//   √ Your memory usage beats 73.28 % of cpp submissions (16.3 MB)