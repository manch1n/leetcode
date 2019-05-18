/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */
#include <string>
using namespace std;
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int vertical = 0;
        int horizon = 0;
        int size = moves.size();
        if (size % 2 != 0)
        {
            return false;
        }
        for (auto c : moves)
        {
            if (c == 'U')
            {
                vertical++;
            }
            else if (c == 'D')
            {
                vertical--;
            }
            else if (c == 'L')
            {
                horizon++;
            }
            else
            {
                horizon--;
            }
        }
        return horizon == 0 && vertical == 0;
    }
};

√ Accepted
  √ 63 / 63 cases passed(20 ms)
  √ Your runtime beats 95.24 % of cpp submissions
  √ Your memory usage beats 59.77 % of cpp submissions(10.3 MB)
