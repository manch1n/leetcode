/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */
#include <string>
using namespace std;
class Solution
{
public:
    inline char itoc(int num)
    {
        return num + 48;
    }
    string convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        string result;
        bool neg = num < 0 ? true : false;
        if (neg)
        {
            num = -num;
        }
        while (num)
        {
            result.insert(result.begin(), itoc(num % 7));
            num = num / 7;
        }
        if (neg)
        {
            result.insert(result.begin(), '-');
        }
        return result;
    }
};

// √ Accepted
//   √ 241/241 cases passed (8 ms)
//   √ Your runtime beats 91.74 % of cpp submissions
//   √ Your memory usage beats 79.2 % of cpp submissions (8.3 MB)