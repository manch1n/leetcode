/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> m;
        for (auto n : deck)
        {
            m[n]++;
        }
        int min_x = (*std::min_element(m.begin(), m.end(), [](const pair<int, int> &left, const pair<int, int> &right) {
                        return left.second < right.second;
                    }))
                        .second;
        if (min_x == 1)
        {
            return false;
        }
        bool flag = true;
        int count = 2;
        while (count <= min_x)
        {
            if (min_x % count != 0)
            {
                count++;
                continue;
            }
            for (auto &n : m)
            {
                if (n.second % count != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;
            flag = true;
            count++;
        }
        return false;
    }
};
// √ Accepted
//   √ 69/69 cases passed (28 ms)
//   √ Your runtime beats 34 % of cpp submissions
//   √ Your memory usage beats 90.85 % of cpp submissions (9.7 MB)