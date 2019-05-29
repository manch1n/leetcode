/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        long base = 1;
        bool flag = false;
        if (n & 1)
        {
            flag = true;
        }
        while (base < n)
        {
            bool tmp = n & base;
            if (/* (n&base) */ tmp != flag) //这里有点奇怪，考虑了隐式cast，可是换成（n&base）就是不行，难道是把flag转成long？
            {
                return false;
            }
            flag = !flag;
            base = base << 1;
        }
        return true;
    }
};

// √ Accepted
//   √ 204/204 cases passed (4 ms)
//   √ Your runtime beats 94.32 % of cpp submissions
//   √ Your memory usage beats 73.72 % of cpp submissions (8.2 MB)