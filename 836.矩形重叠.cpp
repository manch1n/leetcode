/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */
#include <vector>
using namespace std;
class Solution
{
public:
    inline bool inside(const vector<int> &rec, const vector<int> &dot)
    {
        if (dot[0] > rec[0] && dot[0] < rec[2] && dot[1] > rec[1] && dot[1] < rec[3])
        {
            return true;
        }
        else
            return false;
    }
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        //<x1,y1>,<x2,y2>
        return inside(rec1, {rec2[0], rec2[1]}) || inside(rec1, {rec2[2], rec2[3]});
    }
};
// × Wrong Answer
//   × 33/43 cases passed (N/A)
//   × testcase: '[7,8,13,15]\n[10,8,12,20]'
//   × answer: false
//   × expected_answer: true
//   × stdout:
