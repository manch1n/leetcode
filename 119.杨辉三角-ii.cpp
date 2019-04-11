/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (54.56%)
 * Total Accepted:    12.4K
 * Total Submissions: 22.8K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex <= 0)
        {
            return vector<int>{1};
        }
        if (rowIndex == 1)
        {
            return vector<int>{1, 1};
        }
        if (rowIndex == 2)
        {
            return vector<int>{1, 2, 1};
        }
        vector<int> current{1, 1};
        vector<int> next;
        for (int i = 2; i <= rowIndex; i++)
        {
            next.push_back(1);
            for (int j = 0; j <= i - 2; j++)
            {
                next.push_back(current[j] + current[j + 1]);
            }
            next.push_back(1);
            std::swap(next, current);
            next.clear();
        }
        return current;
    }
};

// √ Accepted
//   √ 34/34 cases passed (8 ms)
//   √ Your runtime beats 93.83 % of cpp submissions
//   √ Your memory usage beats 60.28 % of cpp submissions (8.3 MB)