/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        bool carry = false;
        int remain = K % 10;
        int base = A.size() - 1;
        while (K)
        {
            for (int i = base; i >= 0; --i)
            {
                if (carry)
                {
                    if (A[i] == 9)
                    {
                        A[i] = 0;
                    }
                    else
                    {
                        A[i] += 1;
                        carry = false;
                        break;
                    }
                    continue;
                }
                if (A[i] + remain >= 10)
                {
                    carry = true;
                    A[i] = remain + A[i] - 10;
                }
                else
                {
                    A[i] += remain;
                    break;
                }
            }
            if (base < 0 && K)
            {
                if (carry)
                {
                    if (remain != 9)
                    {
                        A.insert(A.begin(), remain + 1);
                        carry = false;
                    }
                    else
                    {
                        A.insert(A.begin(), 0);
                    }
                }
                else
                {
                    A.insert(A.begin(), remain);
                }
            }
            K = K / 10;
            remain = K % 10;
            base -= 1;
        }
        if (carry)
        {
            A.insert(A.begin(), 1);
        }
        return A;
    }
};
// √ Accepted
//   √ 156/156 cases passed (168 ms)
//   √ Your runtime beats 71.62 % of cpp submissions
//   √ Your memory usage beats 91.22 % of cpp submissions (12.3 MB)