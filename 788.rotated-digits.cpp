/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] Rotated Digits
 */
class Solution
{
public:
    bool good[10] = {0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
    bool valid[10] = {1, 1, 1, 0, 0, 1, 1, 0, 1, 1};
    bool isGood(int n)
    {
        int current = 10000;
        bool flag = false;
        while (n)
        {
            if (!valid[n % 10])
            {
                return false;
            }
            if (good[n % 10])
            {
                flag = true;
            }
            n /= 10;
        }
        return flag;
    }
    int rotatedDigits(int N)
    {
        int result = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (isGood(i))
            {
                result++;
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 50/50 cases passed (0 ms)
//   √ Your runtime beats 100 % of cpp submissions
//   √ Your memory usage beats 95.31 % of cpp submissions (8 MB)