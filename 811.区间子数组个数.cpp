/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 区间子数组个数
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void resolveSingle(unordered_map<string, int> &m, string &token)
    {
        int count = std::stoi(token);
        auto i = token.cend();
        auto j = token.cend();
        i--;
        for (; *i != ' '; --i)
        {
            if (*i == '.')
            {
                string tmp(i + 1, j);
                m[tmp] += count;
            }
        }
        string tmp(i + 1, j);
        m[tmp] += count;
    }
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        if (cpdomains.size() == 0)
        {
            return {};
        }
        unordered_map<string, int> m;
        for (auto &str : cpdomains)
        {
            resolveSingle(m, str);
        }
        vector<string> result;
        for (auto &p : m)
        {
            string tmp;
            tmp += to_string(p.second);
            tmp += ' ';
            tmp += p.first;
            result.push_back(tmp);
        }
        return result;
    }
};

// √ Accepted
//   √ 52/52 cases passed (44 ms)
//   √ Your runtime beats 40.08 % of cpp submissions
//   √ Your memory usage beats 69 % of cpp submissions (13.2 MB)
