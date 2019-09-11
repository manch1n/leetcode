/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {
        int remain = 1, current = 0;
        vector<bool> result;
        for (auto n : A)
        {
            if (n == 1)
            {
                current += remain;
                current %= 5;
            }
            result.push_back(current == 0);
            remain = (remain * 2) % 5;
        }
        return result;
    }
};
//it seems that the expected is wrong.32+3=35

// × Wrong Answer
//   × 4/24 cases passed (N/A)
//   × testcase: '[1,1,0,0,0,1,0,0,1]'
//   × answer: [false,false,false,false,false,true,true,true,false]
//   × expected_answer: [false,false,false,false,false,false,false,false,false]
//   × stdout: