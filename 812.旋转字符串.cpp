/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 旋转字符串
 */
#include <vector>
using namespace std;
class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {

        double max_area = 0.0, area = 0.0;
        for (auto &p1 : points)
        {
            for (auto &p2 : points)
            {
                for (auto &p3 : points)
                {
                    area = abs(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] -
                               p2[0] * p1[1] - p3[0] * p2[1] - p1[0] * p3[1]) /
                           2.0;
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};

// √ Accepted
//   √ 57/57 cases passed (48 ms)
//   √ Your runtime beats 23.7 % of cpp submissions
//   √ Your memory usage beats 81.48 % of cpp submissions (9 MB)