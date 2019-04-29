/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    inline bool is_same(string::iterator b,string::iterator e,vector<int> bucket)
    {
        while(b!=e)
        {
            if(--bucket[*b-97]<0) return false;
            b++;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> Vec_i;
        int sizeS=s.size();
        int sizeP=p.size();
        if(sizeP==0||sizeS==0) return {};
        vector<int> bucketP(26,0);
        for(auto n:p)
        {
            bucketP[n-97]++;
        }
        int i=0,j=i+sizeP;
        for(;j<=sizeS;++j,++i)
        {
            if(is_same(s.begin()+i,s.begin()+j,bucketP))
            {
                Vec_i.push_back(i);
            }
        }
        return Vec_i;
    }
};

//果然慢的要死  
// √ Accepted
//   √ 36/36 cases passed (1832 ms)
//   √ Your runtime beats 5.75 % of cpp submissions
//   √ Your memory usage beats 10.46 % of cpp submissions (32.3 MB)