/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 多米诺和托米诺平铺
 */
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string S)
    {
        if (S.size() == 0)
        {
            return {0, 0};
        }
        int lc = 1, left = 100;
        for (auto c : S)
        {
            int index = static_cast<int>(c) - 97;
            if (left - widths[index] >= 0)
            {
                left -= widths[index];
            }
            else
            {
                lc++;
                left = 100 - widths[index];
            }
        }
        return {lc, 100 - left};
    }
};

// √ Accepted
//   √ 26/26 cases passed (8 ms)
//   √ Your runtime beats 64.89 % of cpp submissions
//   √ Your memory usage beats 87.88 % of cpp submissions (8.5 MB)