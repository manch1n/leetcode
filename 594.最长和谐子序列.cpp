/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        map<int, int> m;
        for(auto n:nums)
        {
            m[n]++;
        }
        int res = 0;
        for (auto i = next(m.begin()); i != m.end();++i)
        {
            auto pre = prev(i);
            if(i->first==pre->first+1)
            {
                res = max(res, i->second + pre->second);
            }
        }
        return res;
    }
};

// √ Accepted
//   √ 201/201 cases passed (204 ms)
//   √ Your runtime beats 35.04 % of cpp submissions
//   √ Your memory usage beats 51.4 % of cpp submissions (20.7 MB)