/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (33.83%)
 * Total Accepted:    11.7K
 * Total Submissions: 34.5K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j
 * 的差的绝对值最大为 k。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1], k = 3
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,0,1,1], k = 1
 * 输出: true
 * 
 * 示例 3:
 * 
 * 输入: nums = [1,2,3,1,2,3], k = 2
 * 输出: false
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        /*!O(n^2)果然timeout呢 */
        // int size=nums.size();
        // if(size<=1) return false;
        // for(int i=0;i<size-1;i++)
        //     for(int j=i+1;j<size;j++)
        //     {
        //         if(nums[i]==nums[j])
        //         {
        //             if((j-i)<=k) return true;
        //         }
        //     }
        // return false;
        int size = nums.size();
        if (size <= 1)
            return false;
        unordered_map<int, unsigned> m;
        for (int i = 0; i < size; i++)
        {
            if (m.find(nums[i]) == m.end())
            {
                m[nums[i]] = i;
            }
            else
            {
                if (i - m.find(nums[i])->second <= k)
                    return true;
                else
                {
                    m[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
// √ Accepted
//   √ 23/23 cases passed (48 ms)
//   √ Your runtime beats 72.41 % of cpp submissions
//   √ Your memory usage beats 31.89 % of cpp submissions (15.3 MB)
