/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        if (trust.size() == 0)
        {
            return N;
        }
        unordered_map<int, set<int>> m; //be trusted
        set<int> num;
        for (auto &p : trust)
        {
            m[p[1]].insert(p[0]);
            num.insert(p[0]);
        }
        if (num.size() != N - 1)
        {
            return -1;
        }
        for (auto &t : m)
        {
            if (t.second.size() == N - 1)
            {
                bool flag = true;
                for (auto n : t.second)
                {
                    if (t.first == n)
                    {
                        flag = false;
                    }
                }
                if (flag)
                {
                    return t.first;
                }
            }
        }
        return -1;
    }
};

// √ Accepted
//   √ 89/89 cases passed (532 ms)
//   √ Your runtime beats 5.45 % of cpp submissions
//   √ Your memory usage beats 5.02 % of cpp submissions (59.6 MB)