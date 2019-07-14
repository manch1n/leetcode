/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int distance = -1;
        int max = 1;
        if (seats[0] == 0)
        {
            distance = 0;
            for (int i = 0; i < seats.size(); ++i)
            {
                if (seats[i] == 1)
                {
                    break;
                }
                distance++;
            }
            max = distance;
        }
        if (seats[seats.size() - 1] == 0)
        {
            distance = 0;
            for (int i = seats.size() - 1; i >= 0; --i)
            {
                if (seats[i] == 1)
                {
                    break;
                }
                distance++;
            }
            max = ::max(max, distance);
        }
        for (int i = 0; i < seats.size(); ++i)
        {
            if (seats[i] == 1)
            {
                distance = 0;
                for (int j = i + 1; j < seats.size(); ++j)
                {
                    if (seats[j] == 1)
                    {
                        if (distance % 2 == 1)
                        {
                            max = ::max(max, distance / 2 + 1);
                        }
                        else
                        {
                            max = ::max(max, distance / 2);
                        }
                        break;
                    }
                    distance++;
                }
            }
        }
        return max;
    }
};

// √ Accepted
//   √ 79/79 cases passed (16 ms)
//   √ Your runtime beats 88.18 % of cpp submissions
//   √ Your memory usage beats 88.42 % of cpp submissions (9.9 MB)