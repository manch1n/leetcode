/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (61.03%)
 * Total Accepted:    20.2K
 * Total Submissions: 33.1K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows <= 0)
        {
            return vector<vector<int>>{};
        }
        if (numRows == 1)
        {
            return vector<vector<int>>{{1}};
        }
        if (numRows == 2)
        {
            return vector<vector<int>>{{1}, {1, 1}};
        }
        vector<vector<int>> vecs{{1}, {1, 1}};
        for (int i = 3; i <= numRows; i++)
        {
            vector<int> vec;
            vec.push_back(1);
            for (int j = 0; j < i - 2; j++)
            {
                vec.push_back(vecs[i - 2][j] + vecs[i - 2][j + 1]);
            }
            vec.push_back(1);
            vecs.push_back(vec);
        }
        return vecs;
    }
};

// √ Accepted
//   √ 15/15 cases passed (8 ms)
//   √ Your runtime beats 95.19 % of cpp submissions
//   √ Your memory usage beats 19.31 % of cpp submissions (8.8 MB)