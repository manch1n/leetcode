/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        long base = 1;
        while (1)
        {
            if (base == num)
                return true;
            if (base > num)
                return false;
            base *= 4;
        }
        return false;
    }
};

// √ Accepted
//   √ 1060/1060 cases passed (8 ms)
//   √ Your runtime beats 95.59 % of cpp submissions
//   √ Your memory usage beats 16.58 % of cpp submissions (8.1 MB)