/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        //排序
        unordered_set<string> dict;
        sort(words.begin(), words.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
        for (const auto &w : words)
        {
            if (w.size() == 1)
                dict.insert(w);
            else if (dict.find(w.substr(0, w.size() - 1)) != dict.end())
                dict.insert(w);
        }
        //查找最长的单词
        string cur;
        for (const auto &d : dict)
        {
            if (d.size() == cur.size())
                cur = min(cur, d);
            else if (d.size() > cur.size())
                cur = d;
        }
        return cur;
    }
};

// √ Accepted
//   √ 57/57 cases passed (104 ms)
//   √ Your runtime beats 57.14 % of cpp submissions
//   √ Your memory usage beats 84.71 % of cpp submissions (16.7 MB)