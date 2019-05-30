/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]].push_back(i);
        }
        int min = INT_MAX;
        size_t maxDegree = 0;
        for (auto &n : m)
        {
            if (n.second.size() == 1)
            {
                if (maxDegree < n.second.size())
                {
                    maxDegree = n.second.size();
                    min = 1;
                }
            }
            else
            {
                int d = n.second.size();
                int diff = n.second[n.second.size() - 1] - n.second[0] + 1;
                if (maxDegree < d)
                {
                    maxDegree = d;
                    min = diff;
                }
                else if (maxDegree == d)
                {
                    if (min > diff)
                    {
                        min = diff;
                    }
                }
            }
        }
        return min;
    }
};

// √ Accepted
//   √ 89/89 cases passed (44 ms)
//   √ Your runtime beats 96.27 % of cpp submissions
//   √ Your memory usage beats 11.24 % of cpp submissions (15.6 MB)