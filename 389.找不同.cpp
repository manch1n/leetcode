/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */
#include <string>
using namespace std;
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        if (s.size() == 0 && t.size() == 1)
        {
            return *t.begin();
        }
        int bucket[26]{0};
        for (auto &c : t)
        {
            bucket[static_cast<int>(c) - 97]++;
        }
        for (auto &c : s)
        {
            bucket[static_cast<int>(c) - 97]--;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (bucket[i] == 1)
            {
                return static_cast<char>(i + 97);
            }
        }
        return 'a';
    }
};

// √ Accepted
//   √ 54/54 cases passed (8 ms)
//   √ Your runtime beats 95.97 % of cpp submissions
//   √ Your memory usage beats 86.67 % of cpp submissions (8.9 MB)