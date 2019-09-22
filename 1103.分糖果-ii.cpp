/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public: //(n*2+n)/2
    vector<int> distributeCandies(int candies, int num_people)
    {
        long long cur = 1, left = candies;
        vector<int> result(num_people);
        int i = 0;
        while (left >= 0)
        {
            if (left < cur)
            {
                cur = left;
                left = -1;
            }
            else
            {
                left -= cur;
            }

            result[i] += cur;
            ++i;
            if (i == num_people)
            {
                i = 0;
            }
            cur++;
        }
        return result;
    }
};

// √ Accepted
//   √ 27/27 cases passed (4 ms)
//   √ Your runtime beats 89.45 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (8.5 MB)