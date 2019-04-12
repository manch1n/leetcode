/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (48.13%)
 * Total Accepted:    21.1K
 * Total Submissions: 43.9K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 
 * 说明:
 * 
 * 
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例:
 * 
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        //O(n^2) 果然timeout QAQ  相同的数字要break？？？
        if (numbers.size() <= 1)
        {
            return vector<int>{0, 0};
        }
        int size = numbers.size();
        for (int i = 0; i < size; i++)
        {
            if (numbers[i] > target)
            {
                return vector<int>{0, 0};
            }
            int diff = target - numbers[i];
            if (diff < numbers[i])
            {
                return vector<int>{0, 0};
            }

            if ((i + 1) < size && numbers[i] == numbers[i + 1])
            {
                if (numbers[i + 1] == diff)
                    return vector<int>{i + 1, i + 2};
                continue;
            }
            for (int j = i + 1; j < size; j++)
            {
                if (numbers[j] > diff)
                {
                    break;
                }
                if (numbers[j] == diff)
                {
                    return vector<int>{i + 1, j + 1};
                }
            }
        }
        return vector<int>{0, 0};
    }
};
// √ Accepted
//   √ 17/17 cases passed (12 ms)
//   √ Your runtime beats 95.64 % of cpp submissions
//   √ Your memory usage beats 96.76 % of cpp submissions (9.2 MB)