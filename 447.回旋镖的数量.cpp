/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    inline int dist(vector<int> &l, vector<int> &r)
    {
        return (r[1] - l[1]) * (r[1] - l[1]) + (r[0] - l[0]) * (r[0] - l[0]);
    }

    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int size = points.size();
        if (size < 3)
            return 0;
        int count = 0;
        for (int i = 0; i < size; ++i)
        {
            map<int, int> Map_dist{};
            for (int j = 0; j < size; ++j)
            {
                int d = dist(points[i], points[j]);
                if (Map_dist.find(d) == Map_dist.end())
                {
                    Map_dist[d] = 1;
                }
                else
                {
                    Map_dist[d]++;
                }
            }
            for (auto i = Map_dist.begin(); i != Map_dist.end(); ++i)
            {
                count += i->second * (i->second - 1);
            }
        }
        return count;
    }
};

//不太懂
// √ Accepted
//   √ 31/31 cases passed (1180 ms)
//   √ Your runtime beats 26.73 % of cpp submissions
//   √ Your memory usage beats 6.22 % of cpp submissions (148.1 MB)