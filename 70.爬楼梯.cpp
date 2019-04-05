/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (44.90%)
 * Total Accepted:    39.7K
 * Total Submissions: 88.4K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */
class Solution
{
  public:
    int climbStairs(int n)
    {
        // if (n == 0 || n == 1)
        // {
        //     return 1;
        // }
        // else return climbStairs(n - 1) + climbStairs(n - 2);  //爆栈？？
        int f[3]={1,1,2};
        if(n<=2)
        {
            return f[n];
        }
        n-=2;
        int i=0;
        while(i<n)
        {
            f[i%3]=f[(i+1)%3]+f[(i+2)%3];
            i++;
        }
        return f[(i-1)%3];
    }
};

// √ Accepted
//   √ 45/45 cases passed (4 ms)
//   √ Your runtime beats 23.5 % of cpp submissions
//   √ Your memory usage beats 0.85 % of cpp submissions (8.1 MB)