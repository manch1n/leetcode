/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (43.05%)
 * Total Accepted:    37.1K
 * Total Submissions: 86K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */

#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==0) return 0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
            else if(nums[i]>target)
            {
                return i;
            }
        }
        return len;
    }
};

// √ Accepted
//   √ 62/62 cases passed (12 ms)
//   √ Your runtime beats 16.06 % of cpp submissions
//   √ Your memory usage beats 0.27 % of cpp submissions (8.9 MB)