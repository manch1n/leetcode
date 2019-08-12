/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        unordered_map<string, int> mp;
        for (auto &s : A)
        {
            string even, odd;
            for (int i = 0; i < s.size(); i += 2)
                even.push_back(s[i]);
            for (int i = 1; i < s.size(); i += 2)
                odd.push_back(s[i]);
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            ++mp[even + odd];
        }
        return mp.size();
    }
};
// √ Accepted
//   √ 35/35 cases passed (8 ms)
//   √ Your runtime beats 99.59 % of cpp submissions
//   √ Your memory usage beats 67.09 % of cpp submissions (9.8 MB)