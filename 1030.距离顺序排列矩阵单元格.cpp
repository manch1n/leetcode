/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<vector<int>> m;
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                int r = abs(i - r0);
                int c = abs(j - c0);
                m.push_back(vector<int>{i, j, r + c});
            }
        }
        std::sort(m.begin(), m.end(), [](vector<int> &left, vector<int> &right) {
            return left[2] < right[2];
        });
        for (auto &vec : m)
        {
            vec.resize(2);
        }
        return m;
    }
};

// √ Accepted
//   √ 66/66 cases passed (320 ms)
//   √ Your runtime beats 25.55 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (17.5 MB)