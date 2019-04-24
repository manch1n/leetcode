/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        long left = 0, right = n;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int g = guess(mid);
            if (g == 0)
            {
                return mid;
            }
            else if (g == -1)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return 0;
    }
};

// √ Accepted
//   √ 25/25 cases passed (4 ms)
//   √ Your runtime beats 97.37 % of cpp submissions
//   √ Your memory usage beats 5.38 % of cpp submissions (8.3 MB)