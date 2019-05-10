/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */
#include <vector>
#include <algorithm>
using namespace std;

//排下序即可
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        long result = 0;
        for (int i = 0; i < size; i += 2)
        {
            result += nums[i];
        }
        return result;
    }
};

// √ Accepted
//   √ 81/81 cases passed (108 ms)
//   √ Your runtime beats 48.47 % of cpp submissions
//   √ Your memory usage beats 78.43 % of cpp submissions (11.3 MB)