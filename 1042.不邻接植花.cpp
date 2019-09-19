/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#define PR pair<int, int>
using namespace std;
class Solution
{
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths)
    {
        vector<int> res(N, -1);

        vector<vector<bool>> flag(N, vector<bool>(5, true));
        priority_queue<PR, vector<PR>, greater<PR>> q;
        int x = 0, y = 0;
        for (auto path : paths)
        {
            x = path[0] - 1;
            y = path[1] - 1;
            if (x < y)
            {
                q.push({x, y});
            }
            else
            {
                q.push({y, x});
            }
        }

        while (!q.empty())
        {
            PR path = q.top();
            q.pop();
            x = path.first;
            y = path.second;
            int i = 1;
            while (i < 5 && flag[x][i] == false)
            {
                i++;
            }
            if (i < 5)
            {
                flag[y][i] = false;
            }

            if (res[x] == -1)
            {
                res[x] = i;
                i++;
                while (i < 5)
                {
                    flag[x][i] = false;
                    i++;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (res[i] == -1)
            {
                for (int j = 1; j < 5; j++)
                {
                    if (flag[i][j] == true)
                    {
                        res[i] = j;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
// √ Accepted
//   √ 51/51 cases passed (284 ms)
//   √ Your runtime beats 70.06 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (37.1 MB)