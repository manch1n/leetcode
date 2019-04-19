/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 *
 * https://leetcode-cn.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (45.55%)
 * Total Accepted:    8.5K
 * Total Submissions: 18.5K
 * Testcase Example:  '6'
 *
 * 编写一个程序判断给定的数是否为丑数。
 * 
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 * 
 * 示例 1:
 * 
 * 输入: 6
 * 输出: true
 * 解释: 6 = 2 × 3
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: true
 * 解释: 8 = 2 × 2 × 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: 14
 * 输出: false 
 * 解释: 14 不是丑数，因为它包含了另外一个质因数 7。
 * 
 * 说明：
 * 
 * 
 * 1 是丑数。
 * 输入不会超过 32 位有符号整数的范围: [−2^31,  2^31 − 1]。
 * 
 * 
 */
//动态规划？
class Solution
{
public:
    bool isUgly(int num)
    {
        // if(num==1) return true;
        // if(num==0) return false;
        // bool divide_2,divide_3,divide_5;
        // if(num%2==0)
        // {
        //     divide_2=isUgly(num/2);
        // }
        // else divide_2=false;
        // if(num%3==0)
        // {
        //     divide_3=isUgly(num/3);
        // }
        // else
        // {
        //     divide_3=false;
        // }
        // if(num%5==0)
        // {
        //     divide_5=isUgly(num/5);
        // }
        // else
        // {
        //     divide_5=false;
        // }
        // return divide_2||divide_3||divide_5;

        if (num < 1)
            return false;
        while (1)          //贪心？
        {
            if (num % 2 != 0)
                break;
            else
                num = num / 2;
        }
        while (1)
        {
            if (num % 3 != 0)
                break;
            else
                num = num / 3;
        }
        while (1)
        {
            if (num % 5 != 0)
                break;
            else
                num = num / 5;
        }
        if (num == 1)
            return true;
        else return false;
    }
};

//emmm,递归的动态规划有点惨
// √ Accepted
//   √ 1012/1012 cases passed (144 ms)
//   √ Your runtime beats 5.18 % of cpp submissions
//   √ Your memory usage beats 80.88 % of cpp submissions (7.9 MB)