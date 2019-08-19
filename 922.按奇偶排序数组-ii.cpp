/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int p = 0, q = 1;  //p is even,q is odd
        if(A.size()==0)
            return A;
        vector<int> result(A.size());
        for(auto n:A)
        {
            if(n%2==0)
            {
                result[p] = n;
                p += 2;
            }
            else
            {
                result[q] = n;
                q += 2;
            }
        }
        return result;
    }
};
// √ Accepted
//   √ 61/61 cases passed (172 ms)
//   √ Your runtime beats 37.03 % of cpp submissions
//   √ Your memory usage beats 79.83 % of cpp submissions (11.8 MB)