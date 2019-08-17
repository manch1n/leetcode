/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int smallestRangeI(vector<int> &A, int K)
    {
        int middle = (*max_element(A.begin(), A.end()) + *min_element(A.begin(), A.end())) / 2;
        for (auto &n : A)
        {
            if (n <= middle)
            {
                if ((n + K) >= middle)
                {
                    n = middle;
                }
                else
                {
                    n += K;
                }
            }
            else
            {
                if ((n - K) <= middle)
                {
                    n = middle;
                }
                else
                {
                    n -= K;
                }
            }
        }
        return *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end());
    }
};

// √ Accepted
//   √ 68/68 cases passed (24 ms)
//   √ Your runtime beats 82.7 % of cpp submissions
//   √ Your memory usage beats 91.3 % of cpp submissions (9.6 MB)