/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        vector<int> zeros(arr.size());
        int zerocount = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            zeros[i] = zerocount;
            if (arr[i] == 0)
            {
                zerocount++;
            }
        }
        int prev = zeros[zeros.size() - 1];
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            if (zeros[i] != prev)
            {
                if ((i + prev) < arr.size())
                {
                    arr[i + prev] = 0;
                }
                prev = zeros[i];
            }
            if ((i + zeros[i]) < arr.size())
            {
                arr[i + zeros[i]] = arr[i];
            }
        }
    }
};
// √ Accepted
//   √ 30/30 cases passed (40 ms)
//   √ Your runtime beats 66.88 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (9.5 MB)