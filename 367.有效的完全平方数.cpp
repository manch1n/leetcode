/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        // if(num==0) return true;
        // long base=1;
        // for(;base*base<=num;base++)
        // {
        //     if(base*base==num) return true;
        // }
        // return false;
        //二分法
        long left = 0, right = num;
        while (left <= right)
        {
            long mid = (left + right) / 2;
            long result = mid * mid;
            if (result == num)
                return true;
            if (result < num)
            {
                left = mid + 1;
            }
            else if (result > num)
            {
                right = mid - 1;
            }
        }
        return false;
    }
};

// √ Accepted
//   √ 68/68 cases passed (8 ms)
//   √ Your runtime beats 60.9 % of cpp submissions
//   √ Your memory usage beats 24.6 % of cpp submissions (8.1 MB)

// √ Accepted
//   √ 68/68 cases passed (8 ms)
//   √ Your runtime beats 60.9 % of cpp submissions
//   √ Your memory usage beats 45.99 % of cpp submissions (8 MB)