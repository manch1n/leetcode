/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小移动次数使数组元素相等
 */
#include <vector>
using namespace std;
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int min = INT_MAX;
        long sum = 0, res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (nums[i] < min)
            {
                min = nums[i];
            }
        }
        return sum - min * nums.size();
    }
};


// √ Accepted
//   √ 84/84 cases passed (60 ms)
//   √ Your runtime beats 76.58 % of cpp submissions
//   √ Your memory usage beats 68.64 % of cpp submissions (11.1 MB)