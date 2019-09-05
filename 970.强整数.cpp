/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        set<int> _s;
        for (int tmpx = 1; tmpx <= bound; tmpx *= x)
        {
            for (int tmpy = 1; tmpy <= bound; tmpy *= y)
            {
                if (tmpx + tmpy <= bound)
                {
                    _s.insert(tmpx + tmpy);
                }
                else
                {
                    break;
                }
                if (y == 1)
                {
                    break;
                }
            }
            if (x == 1)
                break;
        }
        vector<int> result(_s.begin(), _s.end());
        return result;
    }
};

// √ Accepted
//   √ 93/93 cases passed (8 ms)
//   √ Your runtime beats 53.31 % of cpp submissions
//   √ Your memory usage beats 88.6 % of cpp submissions (8.3 MB)