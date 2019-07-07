/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 扁平化多级双向链表
 */
#include <vector>
using namespace std;
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j;
        while (i < row - 1) //这里是row-1，最后一行不用再比较
        {
            j = 0;
            while (j < col - 1) //col-1，每行最后一个元素不用比较
            {
                if (matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
                j++;
            }
            i++;
        }
        return true;
    }
};
// √ Accepted
//   √ 482/482 cases passed (32 ms)
//   √ Your runtime beats 18.78 % of cpp submissions
//   √ Your memory usage beats 88.44 % of cpp submissions (9.6 MB)