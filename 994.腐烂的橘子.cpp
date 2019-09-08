/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        vector<pair<int, int>> directs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0)
                    count++;
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }
        if (q.size() == count)
            return 0;
        pair<int, int> pos;
        int res = 0;
        while (!q.empty())
        {
            int size = q.size();
            res++;
            while (size-- > 0)
            {
                pos = q.front();
                q.pop();
                count--;
                for (auto direct : directs)
                {
                    int x = pos.first, y = pos.second;
                    x += direct.first;
                    y += direct.second;
                    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push(make_pair(x, y));
                }
            }
        }
        return count == 0 ? res - 1 : -1;
    }
};
// √ Accepted
//   √ 303/303 cases passed (20 ms)
//   √ Your runtime beats 8.85 % of cpp submissions
//   √ Your memory usage beats 88.46 % of cpp submissions (9.2 MB)