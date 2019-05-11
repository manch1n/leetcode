/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int origini = nums.size();
        int originj = nums[0].size();
        if (origini * originj != r * c)
        {
            return nums;
        }
        vector<vector<int>> result(r);
        int currenti = 0, currentj = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (currentj == originj)
                {
                    currentj = 0;
                    currenti += 1;
                }
                result[i].push_back(nums[currenti][currentj]);
                ++currentj;
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 56/56 cases passed (64 ms)
//   √ Your runtime beats 49.55 % of cpp submissions
//   √ Your memory usage beats 35.47 % of cpp submissions (12.3 MB)