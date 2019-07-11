/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 使序列递增的最小交换次数
 */
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        map<string, int> m;
        auto i = paragraph.cbegin();
        auto j = paragraph.cbegin();
        while (j != paragraph.cend() && isalpha(*j))
        {
            ++j;
        }
        while (1)
        {
            string tmp(i, j);
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            m[tmp]++;
            i = j;
            if (j == paragraph.cend())
            {
                break;
            }
            while (i != paragraph.cend() && !isalpha(*i))
            {
                ++i;
            }
            j = i;
            while (j != paragraph.cend() && isalpha(*j))
            {
                ++j;
            }
        }
        m[""] = INT_MIN;
        vector<pair<string, int>> vecp(m.cbegin(), m.cend());
        std::sort(vecp.begin(), vecp.end(), [](const pair<string, int> &i, pair<string, int> &j) {
            return i.second > j.second;
        });
        for (auto &p : vecp)
        {
            if (find(banned.begin(), banned.end(), p.first) == banned.end())
            {
                return p.first;
            }
        }
        return {};
    }
};
// √ Accepted
//   √ 47/47 cases passed (12 ms)
//   √ Your runtime beats 68.61 % of cpp submissions
//   √ Your memory usage beats 73.33 % of cpp submissions (9.1 MB)