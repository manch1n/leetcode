/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */
class Solution {
public:
    int getSum(int a, int b) {
        // if(a==0) return b;
        // if(b==0) return a;
        // int base=1;
        // int result=0;
        // bool carry=false;
        // for(int i=1;i<32;i++)
        // {
        //     if((a&base)&&(b&base))
        //     {
        //         if(carry)
        //         {
        //             result|=base;
        //         }
        //         else
        //         {
        //             carry=true;
        //         }
        //     }
        //     else if((a&base)||(b&base))
        //     {
        //         if(carry)
        //         {
        //         }
        //         else
        //         {
        //             result|=base;
        //         }
        //     }
        //     else
        //     {
        //         if(carry)
        //         {
        //             carry=false;
        //             result|=base;
        //         }
        //     }
        //     base=base<<1;
        // }
        // if(/* (a&base)&&(b&base) */a<0&&b<0)  //both signed
        // {
        //     result|=base;
        // }
        // return result;
        // 分析： 考虑用移位运算符进行加法运算。用异或算出不进位加法结果，用与运算算出要进位的位，然后左移得到进位的正确位置，循环直到与运算结果为0.
        int tmp=0;
        while(b!=0)
        {
            tmp=(a&b)<<1;
            a=a^b;
            b=tmp;
        }
        return a;
    }
};


//emmmm:实在不会
// × Wrong Answer
//   × 12/13 cases passed (N/A)
//   × testcase: '2147483647\n-2147483648'
//   × answer: 2147483647
//   × expected_answer: -1
//   × stdout: