/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
#include <vector>
using namespace std;
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int size = nums.size();
        bool flag = false;
        for (int i = 0; i < size - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                if (i == 0)
                {
                    flag = true;
                }
                else
                {
                    if (flag)
                    {
                        return false;
                    }
                    else
                    {
                        flag = true;
                    }
                    if (nums[i - 1] > nums[i + 1]) //maybe i should be smaller and maybe i+1 should be grater
                    {
                        if ((i + 2) < size && nums[i + 2] > nums[i])
                        {
                            continue;
                        }
                        if (i == size - 2)
                        {
                            return true;
                        }
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// √ Accepted
//   √ 325/325 cases passed (36 ms)
//   √ Your runtime beats 94 % of cpp submissions
//   √ Your memory usage beats 68.42 % of cpp submissions (10.4 MB)
