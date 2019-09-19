/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q;
        for (auto n : stones)
        {
            q.push(n);
        }
        while (q.size() > 1)
        {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            if (x != y)
            {
                q.push(std::abs(x - y));
            }
        }
        if (q.size() == 1)
        {
            return q.top();
        }
        else
        {
            return 0;
        }
    }
};

// √ Accepted
//   √ 70/70 cases passed (4 ms)
//   √ Your runtime beats 86.25 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (8.3 MB)