/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */
class Solution
{
public:
    bool isPrime[32] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0};
    inline int setNum(int n)
    {
        int current = 1;
        int sum = 0;
        while (current <= n)
        {
            if (n & current)
            {
                sum += 1;
            }
            current = current << 1;
        }
        return sum;
    }
    int countPrimeSetBits(int L, int R)
    {
        int sum = 0;
        for (int i = L; i <= R; ++i)
        {
            if (isPrime[setNum(i) - 1])
            {
                sum += 1;
            }
        }
        return sum;
    }
};

// √ Accepted
//   √ 200/200 cases passed (52 ms)
//   √ Your runtime beats 31.38 % of cpp submissions
//   √ Your memory usage beats 91.23 % of cpp submissions (8.1 MB)
