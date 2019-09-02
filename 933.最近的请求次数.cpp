/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */
#include <queue>
using namespace std;
class RecentCounter
{
public:
    queue<int> q;
    RecentCounter() : q()
    {
    }

    int ping(int t)
    {
        q.push(t);
        while (q.front() < t - 3000)
            q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

// √ Accepted
//   √ 68/68 cases passed (316 ms)
//   √ Your runtime beats 62.95 % of cpp submissions
//   √ Your memory usage beats 82.93 % of cpp submissions (49.9 MB)