/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */
class Solution
{
public:
    int findComplement(int num)
    {
        long base = 1;
        int result = 0;
        while (base < num)
        {
            if (!(base & num))
            {
                result += base;
            }
            base = base << 1;
        }
        return result;
    }
};

// √ Accepted
//   √ 149/149 cases passed (8 ms)
//   √ Your runtime beats 94.6 % of cpp submissions
//   √ Your memory usage beats 67.65 % of cpp submissions (8.3 MB)