/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 *
 * [1041] 困于环中的机器人
 */
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0;
        int dir = 0;
        for (int i = 0; i < 4; ++i)
        {
            for (char c : instructions)
            {
                switch (c)
                {
                case 'G':
                {
                    if (dir == 0)
                    {
                        x += 1;
                    }
                    else if (dir == 1)
                    {
                        y += 1;
                    }
                    else if (dir == 2)
                    {
                        x -= 1;
                    }
                    else
                    {
                        y -= 1;
                    }
                    break;
                }
                case 'L':
                {
                    dir += 1;
                    dir %= 4;
                    break;
                }
                case 'R':
                {
                    if (dir == 0)
                    {
                        dir = 3;
                        break;
                    }
                    dir -= 1;
                    dir %= 4;
                    break;
                }
                default:
                {
                    break;
                }
                }
            }
        }
        return x == 0 && y == 0;
    }
};
// √ Accepted
//   √ 110/110 cases passed (4 ms)
//   √ Your runtime beats 74.27 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (8.3 MB)