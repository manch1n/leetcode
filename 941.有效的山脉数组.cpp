/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        int size = A.size();
        if (size < 3)
        {
            return false;
        }
        bool falg = true;
        for (int i = 1; i < size; ++i)
        {
            if (A[i] == A[i - 1])
            {
                return false;
            }
            else if (A[i - 1] > A[i])
            {
                if (falg)
                {
                    falg = false;
                }
            }
            else
            {
                if (!falg)
                {
                    return false;
                }
            }
        }
        if (falg == true || A[0] > A[1])
        {
            return false;
        }
        else
            return true;
    }
};

// √ Accepted
//   √ 51/51 cases passed (48 ms)
//   √ Your runtime beats 37.75 % of cpp submissions
//   √ Your memory usage beats 88.89 % of cpp submissions (10.3 MB)