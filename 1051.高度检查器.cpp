/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> tmp(heights);
        std::sort(heights.begin(), heights.end());
        int res = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            if (heights[i] != tmp[i])
            {
                res++;
            }
        }
        return res;
    }
};

// √ Accepted
//   √ 79/79 cases passed (4 ms)
//   √ Your runtime beats 86.89 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (8.3 MB)