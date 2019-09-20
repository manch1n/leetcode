/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> result;
        string pattern = first;
        pattern += " ";
        pattern += second;
        string::size_type n = 0;
        int offset = pattern.size();
        while ((n = text.find(pattern, n)) != string::npos)
        {
            string::size_type thirdloc = n + offset + 1;
            string::size_type thirdend;
            if (thirdloc >= text.size())
            {
                break;
            }
            if ((thirdend = text.find(' ', thirdloc)) != string::npos)
            {
                result.push_back(string(text.begin() + thirdloc, text.begin() + thirdend));
            }
            else
            {
                result.push_back(string(text.begin() + thirdloc, text.end()));
            }
            n += offset;
        }
        return result;
    }
};
//有毒
// √ Finished
//   √ Your Input: "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa"
// "kcyxdfnoa"
// "jkypmsxd"
//   √ Output (0 ms): ["kcyxdfnoa","kcyxdfnoa","kcyxdfnoa"]
//   √ Expected (24 ms): ["kcyxdfnoa","kcyxdfnoa","kcyxdfnoa"]
//   √ Stdout:

// × Wrong Answer
//   × 28/29 cases passed (N/A)
//   × Testcase: "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa"
// "kcyxdfnoa"
// "jkypmsxd"
//   × Answer:
//   × Stdout: '["girl","student"]'