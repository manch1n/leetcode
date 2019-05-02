/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int base = 1;
        int diff = x ^ y;
        int count = 0;
        for (int i = 0; i < 31; ++i)
        {
            if (diff & base)
            {
                count++;
            }
            base = base << 1;
        }
        return count;
    }
};

// √ Accepted
//   √ 149/149 cases passed (8 ms)
//   √ Your runtime beats 95.31 % of cpp submissions
//   √ Your memory usage beats 73.79 % of cpp submissions (8.3 MB)