/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:

    void read(vector<string>& vecs,int num,int hour)   //num为分配给分钟的。
    {
        if(num<0) return;
        for(int i=0;i<=59;i++)
        {
            if(bit_num(i)==num)
            {
                if(i<10)
                {
                    vecs.push_back(to_string(hour)+":0"+to_string(i));
                }
                else
                {
                    vecs.push_back(to_string(hour)+":"+to_string(i));
                }
            }
        }
    }

    int bit_num(int num)
    {
        int base=1;
        int count=0;
        for(int i=0;i<32;i++)
        {
            if(num<base) break;
            if(num&base) count++;
            base=base<<1;
        }
        return count;
    }

    vector<string> readBinaryWatch(int num) {
        if(num<=0) return{"0:00"}; //排列组合
        if(num>=10) return {"11:59"};
        vector<string> vecs{};
        for(int i=0;i<=11;i++)  //分配给小时亮的灯
        {
            read(vecs,num-bit_num(i),i);
        }
        return vecs;
    }
};

// √ Accepted
//   √ 10/10 cases passed (8 ms)
//   √ Your runtime beats 94.93 % of cpp submissions
//   √ Your memory usage beats 74.74 % of cpp submissions (8.7 MB)