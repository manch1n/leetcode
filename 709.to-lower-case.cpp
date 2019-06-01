/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] To Lower Case
 */
#include <string>
using namespace std;
class Solution
{
public:
    string toLowerCase(string str)
    {
        //emmm
        for (auto &c : str)
        {
            if (c >= 65 && c <= 90)
            {
                c += 32;
            }
        }
        return str;
    }
};

// √ Accepted
//   √ 8/8 cases passed (4 ms)
//   √ Your runtime beats 96.77 % of cpp submissions
//   √ Your memory usage beats 7.27 % of cpp submissions (8.3 MB)