/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的K-diff数对
 */
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        //直接用平方的暴力算法把
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int result = 0;
        int previ = numeric_limits<int>::min();
        int prevj = -1;
        for (int i = 0; i < size - 1; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                if ((nums[j] - nums[i]) < k)
                {
                    continue;
                }
                else if ((nums[j] - nums[i]) == k)
                {
                    if (nums[i] != previ)
                    {
                        result += 1;
                    }
                    previ = nums[i];
                    prevj = nums[j];
                }
                else
                    break;
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 72/72 cases passed (72 ms)
//   √ Your runtime beats 42.42 % of cpp submissions
//   √ Your memory usage beats 81.82 % of cpp submissions (9.8 MB)