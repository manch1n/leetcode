/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 破解保险箱
 */
class Solution
{
public:
    int reachNumber(int target)
    {
        target = abs(target);
        int step = 0, sum = 0;
        while (sum < target || (sum - target) % 2 != 0)
        {
            step += 1;
            sum += step;
        }
        return step;
    }
};
// √ Accepted
//   √ 73/73 cases passed (8 ms)
//   √ Your runtime beats 64.29 % of cpp submissions
//   √ Your memory usage beats 81.69 % of cpp submissions (8.2 MB)