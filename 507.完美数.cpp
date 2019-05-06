/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */
#include <vector>
using namespace std;
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        int sum = 1;
        for (int i = 2; i * i <= num; ++i)
        {
            if (num % i == 0)
                sum += (i + num / i);
            if (i * i == num)
                sum -= i;
            if (sum > num)
                return false;
        }
        return sum == num;
    }
};

//这还timeout 醉了。
// × Time Limit Exceeded
//   × 45/156 cases passed (N/A)
//   × testcase: '24036583'
//   × answer:
//   × expected_answer:
//   × stdout:

// √ Accepted
//   √ 156/156 cases passed (8 ms)
//   √ Your runtime beats 95.37 % of cpp submissions
//   √ Your memory usage beats 80.46 % of cpp submissions (8.3 MB)