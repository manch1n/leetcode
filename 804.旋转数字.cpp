/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 旋转数字
 */
#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution
{
public:
    vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int uniqueMorseRepresentations(vector<string> &words)
    {
        set<string> s;
        for (auto &str : words)
        {
            string tmp;
            for (auto c : str)
            {
                tmp += morse[static_cast<int>(c) - 97];
            }
            s.insert(tmp);
        }
        return s.size();
    }
};

// √ Accepted
//   √ 83/83 cases passed (16 ms)
//   √ Your runtime beats 23.16 % of cpp submissions
//   √ Your memory usage beats 72.64 % of cpp submissions (9.1 MB)
