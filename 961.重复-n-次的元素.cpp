/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 重复 N 次的元素
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        unordered_map<int, int> map;
        for (auto n : A)
        {
            map[n]++;
        }
        for (auto &i : map)
        {
            if (i.second == A.size() / 2)
            {
                return i.first;
            }
        }
        return 0;
    }
};

// √ Accepted
//   √ 102/102 cases passed (136 ms)
//   √ Your runtime beats 7.33 % of cpp submissions
//   √ Your memory usage beats 10.23 % of cpp submissions (16.7 MB)