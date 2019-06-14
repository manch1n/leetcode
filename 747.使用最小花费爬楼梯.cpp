/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 使用最小花费爬楼梯
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //找到第一和第二大的元素
    int dominantIndex(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }
        int max1 = 0, index = -1, max2;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > max1)
            {
                index = i;
                max2 = max1;
                max1 = nums[i];
            }
            else
            {
                if (nums[i] > max2)
                {
                    max2 = nums[i];
                }
            }
        }
        if (max1 >= max2 * 2)
        {
            return index;
        }
        else
            return -1;
    }
};

// √ Accepted
//   √ 250/250 cases passed (8 ms)
//   √ Your runtime beats 85.8 % of cpp submissions
//   √ Your memory usage beats 79.49 % of cpp submissions (8.4 MB)