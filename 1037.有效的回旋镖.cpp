/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        if ((points[0][0] == points[1][0] && points[0][1] == points[1][1]) || (points[0][0] == points[2][0] && points[0][1] == points[2][1]) || (points[1][0] == points[2][0] && points[1][1] == points[2][1]))
        {
            return false;
        }
        else
        {
            int x = points[2][0], y = points[2][1];
            int x1 = points[0][0], y1 = points[0][1];
            int x2 = points[1][0], y2 = points[1][1];
            if ((y - y1) * (x2 - x1) == (y2 - y1) * (x - x1))
                return false;
        }
        return true;
    }
};
// √ Accepted
//   √ 190/190 cases passed (4 ms)
//   √ Your runtime beats 82.49 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (8.4 MB)