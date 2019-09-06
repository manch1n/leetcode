/*
 * @lc app=leetcode.cn id=985 lang=cpp
 *
 * [985] 查询后的偶数和
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        int sum = 0;
        std::for_each(A.begin(), A.end(), [&](const int &n) {
            if (n % 2 == 0)
            {
                sum += n;
            }
        });
        vector<int> result;
        for (auto &q : queries)
        {
            int val = q[0];
            int index = q[1];
            int tmp = A[index] + val;
            if (tmp % 2 == 0)
            {
                if (A[index] % 2 == 0)
                {
                    sum += val;
                }
                else
                {
                    sum = sum + val + A[index];
                }
            }
            else
            {
                if (A[index] % 2 == 0)
                {
                    sum -= A[index];
                }
                else
                {
                }
            }
            result.push_back(sum);
            A[index] += val;
        }
        return result;
    }
};

// √ Accepted
//   √ 58/58 cases passed (372 ms)
//   √ Your runtime beats 9.3 % of cpp submissions
//   √ Your memory usage beats 75.8 % of cpp submissions (28.8 MB)