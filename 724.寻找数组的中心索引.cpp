/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */
#include <vector>
using namespace std;
class Solution
{
public:
    //greedy
    int pivotIndex(vector<int> &nums)
    {
        //不是贪心我搞错了emm
        // if (nums.size() <= 1)
        // {
        //     return -1;
        // }
        // int i = 0, j = nums.size() - 1;
        // int left = 0, right = 0;
        // while (i <= j)
        // {
        //     int tmpl = left + nums[i];
        //     int tmpr = right + nums[j];
        //     if(abs(tmpl-right)<abs(tmpr-left))
        //     {
        //         left += nums[i];
        //         i += 1;
        //     }
        //     else
        //     {
        //         right += nums[j];
        //         j -= 1;
        //     }

        //     if (i == j)
        //     {
        //         if (left == right)
        //         {
        //             return i;
        //         }
        //         else
        //         {
        //             return -1;
        //         }
        //     }
        // }
        // return -1;
        int size = nums.size();
        vector<int> left(nums);
        vector<int> right(nums);
        for (int i = 1; i < size; ++i)
        {
            left[i] += left[i - 1];
        }
        for (int j = size - 2; j >= 0; --j)
        {
            right[j] += right[j + 1];
        }
        for (int i = 0; i < size; ++i)
        {
            if (left[i] == right[i])
            {
                return i;
            }
        }
        return -1;
    }
};

// √ Accepted
//   √ 741/741 cases passed (36 ms)
//   √ Your runtime beats 84.14 % of cpp submissions
//   √ Your memory usage beats 74.95 % of cpp submissions (11 MB)
