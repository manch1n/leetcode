/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        int left = 0, right = S.size();
        vector<int> result;
        for (auto c : S)
        {
            if (c == 'I')
            {
                result.push_back(left);
                left++;
            }
            else
            {
                result.push_back(right);
                right--;
            }
        }
        result.push_back(left);
        return result;
    }
};

// √ Accepted
//   √ 95/95 cases passed (56 ms)
//   √ Your runtime beats 93.43 % of cpp submissions
//   √ Your memory usage beats 74.65 % of cpp submissions (10.5 MB)