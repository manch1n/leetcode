/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 车的可用捕获量
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int result = 0;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (board[i][j] == 'R')
                {
                    //up
                    for (int up = j - 1; up >= 0; --up)
                    {
                        if (board[i][up] == 'B')
                        {
                            break;
                        }
                        else if (board[i][up] == 'p')
                        {
                            result++;
                            break;
                        }
                    }
                    //down
                    for (int down = j + 1; down < 8; ++down)
                    {
                        if (board[i][down] == 'B')
                        {
                            break;
                        }
                        else if (board[i][down] == 'p')
                        {
                            result++;
                            break;
                        }
                    }
                    //right
                    for (int ri = i + 1; ri < 8; ++ri)
                    {
                        if (board[ri][j] == 'B')
                        {
                            break;
                        }
                        else if (board[ri][j] == 'p')
                        {
                            result++;
                            break;
                        }
                    }
                    //left
                    for (int ri = i - 1; ri >= 0; --ri)
                    {
                        if (board[ri][j] == 'B')
                        {
                            break;
                        }
                        else if (board[ri][j] == 'p')
                        {
                            result++;
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};
// √ Accepted
//   √ 22/22 cases passed (4 ms)
//   √ Your runtime beats 77.74 % of cpp submissions
//   √ Your memory usage beats 48.8 % of cpp submissions (8.5 MB)