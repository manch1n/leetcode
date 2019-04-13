/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (58.44%)
 * Total Accepted:    34.8K
 * Total Submissions: 59.6K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        //O(n^2) 果然timeout呢。
        int size = nums.size();
        for (int estimate_i = 0; estimate_i < size; /* estimate_i+=2 */) //这种回溯在前者都不是众数的情况下演变为了O(n^2)
        {
            int frequency = 0;
            for (int i = 0; i < size; i++)
            {
                if (nums[i] == nums[estimate_i])
                    frequency++;
                if (frequency > size / 2)
                {
                    return nums[i];
                }
            }
            estimate_i = (estimate_i + size / 4 + 1) % size;  //替换为这种回溯策略
        }
        return nums[0];
    }
};

// √ Accepted
//   √ 44/44 cases passed (28 ms)
//   √ Your runtime beats 92.57 % of cpp submissions
//   √ Your memory usage beats 81.22 % of cpp submissions (11 MB)
