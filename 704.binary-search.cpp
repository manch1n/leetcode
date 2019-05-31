/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include <vector>
using namespace std;
class Solution
{
public:
    //直接遍历一遍不就完事了。何必二叉搜索。
    int search(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};

// √ Accepted
//   √ 46/46 cases passed (56 ms)
//   √ Your runtime beats 87.21 % of cpp submissions
//   √ Your memory usage beats 70.18 % of cpp submissions (11 MB)