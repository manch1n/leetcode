/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
class Solution
{
public:
    //用一个循环队列足以
    int fib(int N)
    {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        int f[3]{0, 1, 0};
        int c = 2;
        while (c <= N)
        {
            f[c % 3] = f[(c + 1) % 3] + f[(c + 2) % 3];
            ++c;
        }
        return f[(c - 1) % 3];
    }
};

// √ Accepted
//   √ 31/31 cases passed (4 ms)
//   √ Your runtime beats 98.36 % of cpp submissions
//   √ Your memory usage beats 30.37 % of cpp submissions (8.4 MB)