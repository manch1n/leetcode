/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> result;
        for (auto &n : nums)
        {
            int index = abs(n) - 1;
            if (nums[index] > 0)
            {
                nums[index] = -nums[index];
            }
            else
            {
                result.push_back(index + 1);
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

√ Accepted
  √ 49 / 49 cases passed(44 ms)
  √ Your runtime beats 94.97 % of cpp submissions
  √ Your memory usage beats 89.65 % of cpp submissions(10.5 MB)
