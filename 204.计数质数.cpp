/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (27.05%)
 * Total Accepted:    15.6K
 * Total Submissions: 57.4K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */
#include <cstring>
class Solution
{
public:
    //果然timeout了2333
    // bool isPrime(int n)
    // {
    //     if(n==2) return true;
    //     for(int i=2;i<=n/2;i++)
    //     {
    //         if(n%i==0) return false;
    //     }
    //     return true;
    // }
    int countPrimes(int n)
    {
        // int count=0;
        // for(int i=2;i<n;i++)
        // {
        //     if(isPrime(i)) count++;
        // }
        // return count;
        if (n == 2)
            return 0;
        auto is_prime = new bool[n];
        memset(is_prime, 0, sizeof(bool) * n);
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (is_prime[i] == false)
            {
                count++;
                for (int j = 2; i * j < n; j++)
                {
                    is_prime[i * j] = true;
                }
            }
        }
        delete[] is_prime;
        return count;
    }
};

// √ Accepted
//   √ 20/20 cases passed (64 ms)
//   √ Your runtime beats 69.74 % of cpp submissions
//   √ Your memory usage beats 31.31 % of cpp submissions (11.4 MB)
