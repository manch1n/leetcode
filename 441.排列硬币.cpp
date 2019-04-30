/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */
class Solution
{
public:
    // 数学的等差数列？？
    int arrangeCoins(int n)
    {
        if (n == 1)
            return 1;
        int mid = n / 2;
        int left = 0, right = n;
        while (left <= right)
        {
            long sum1 = (1 + (long)mid) * (long)mid / 2;
            long sum2 = sum1 - mid;
            if (sum2 <= n && sum1 > n)
            {
                return mid - 1;
            }
            else if (sum2 > n)
            {
                right = mid - 1;
                mid = (left + right) / 2;
            }
            else
            {
                left = mid + 1;
                mid = (left + right) / 2;
            }
        }
        return 0;
    }
};

// √ Accepted
//   √ 1336/1336 cases passed (12 ms)
//   √ Your runtime beats 99.05 % of cpp submissions
//   √ Your memory usage beats 73.33 % of cpp submissions (8.4 MB)