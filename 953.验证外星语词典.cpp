/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //true:left>right
    inline bool alienCmp(const string &left, const string &right, unordered_map<char, int> &orderMap)
    {
        int minSize = min(left.size(), right.size());
        for (int i = 0; i < minSize; ++i)
        {
            if (orderMap[left[i]] < orderMap[right[i]])
            {
                return false;
            }
            else if (orderMap[left[i]] > orderMap[right[i]])
            {
                return true;
            }
        }
        return left.size() > right.size();
    }
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> map;
        for (int i = 0; i < 26; ++i)
        {
            map[order[i]] = i;
        }
        for (int i = 1; i < words.size(); ++i)
        {
            if (!alienCmp(words[i], words[i - 1], map))
            {
                return false;
            }
        }
        return true;
    }
};

// √ Accepted
//   √ 115/115 cases passed (4 ms)
//   √ Your runtime beats 99.06 % of cpp submissions
//   √ Your memory usage beats 80.85 % of cpp submissions (9.5 MB)