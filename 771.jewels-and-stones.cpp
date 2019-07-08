/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_set<char> s;
        for (auto c : J)
        {
            s.insert(c);
        }
        int count = 0;
        for (auto c : S)
        {
            if (s.find(c) != s.end())
            {
                count++;
            }
        }
        return count;
    }
};

// √ Accepted
//   √ 254/254 cases passed (4 ms)
//   √ Your runtime beats 93.33 % of cpp submissions
//   √ Your memory usage beats 75.4 % of cpp submissions (8.6 MB)