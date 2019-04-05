/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.66%)
 * Total Accepted:    46.2K
 * Total Submissions: 105.6K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
//思路：类似于插入排序的分治法，把第i个元素的前子序列的最大值求出，然后包括第i个元素的子序列的最大值就是如果是正数，则加上自己，如果是负数则仍为前者。
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        //O(n)
        // int current = nums[0];
        // int sum = nums[0];
        // int len = nums.size();
        // for (int i = 1; i < len; i++)
        // {
        //     if (current < 0)
        //         current = nums[i];
        //     else
        //         current += nums[i];
        //     if (current > sum)
        //         sum = current;
        // }
        // return sum;


        //O(n)
        int current=nums[0];
        int sum=nums[0];
        int len=nums.size();
        for(int i=1;i<len;i++)
        {
            if(current>0) current+=nums[i];
            else current=nums[i];
            if(current>sum) sum=current;
        }
        return sum;
    }
};

// √ Accepted
//   √ 202/202 cases passed (20 ms)
//   √ Your runtime beats 18.72 % of cpp submissions
//   √ Your memory usage beats 0.94 % of cpp submissions (9 MB)
