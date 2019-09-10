/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */
class Solution
{
public:
    int bitwiseComplement(int N)
    {
        if (N == 0)
            return 1;
        int base = 1;
        while (base <= N)
        {
            base *= 2;
        }
        return base - N - 1;
    }
};

// √ Accepted
//   √ 128/128 cases passed (4 ms)
//   √ Your runtime beats 72.43 % of cpp submissions
//   √ Your memory usage beats 87.55 % of cpp submissions (8 MB)