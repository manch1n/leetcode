/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第N个数字
 */

//找规律：
//个位数：1-9，一共9个,共计9个数字
//2位数：10-99,一共90个，共计180个数字
//3位数：100-999，一共900个，共计270个数字
//4位数，1000-9999，一共9000个，共计36000个数字
class Solution {
public://丧心病狂的简单题
    int findNthDigit(int n) {
        //避免从1开始找
        // if(n<=9) return n;
        // int base=1;
        // int num=1;
        // long b=9;
        // long sum=0;
        // for(int i=1;;++i)
        // {
        //     sum+=b*i;
        //     if(n<=sum) 
        //     {
        //         sum-=b*i;
        //         break;
        //     }
        //     b*=10;
        //     base*=10;
        // }
        // num=base;  //sum 9 base 10 n 10
        // for(int i=sum+1;i<=n;)
        // {
        //     int tmp=num;
        //     while(base)
        //     {
        //         if(i==n)
        //         {
        //             return num/base;
        //         }
        //         num=num%base;
        //         base/=10;
        //         i++;
        //     }
        //     num=tmp+1;
        //     base=1;
        //     while(num/=10) base*=10;
        //     num=tmp+1;
        // }
        // return 0;
        int len = 1, base = 1;
        while(n>9L*base*len){
            n -= 9*base*len;
            len++;
            base *= 10;
        }
        int curNum = (n-1)/len + base, digit = 0;
        for(int i=(n-1)%len;i<len;++i){
            digit = curNum%10;
            curNum /= 10;
        }
        return digit;
    }
};


//果然timeout了emmmmmm
// × Time Limit Exceeded
//   × 37/70 cases passed (N/A)
//   × testcase: '1000000000'
//   × answer: 
//   × expected_answer: 
//   × stdout: