/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> result;
        for (auto &str : logs)
        {
            if (isalpha(str[str.size() - 1]))
            {
                result.push_back(str);
            }
        }
        std::sort(result.begin(), result.end(), [](const string &left, const string &right) {
            return left.substr(left.find(' ') + 1) <= right.substr(right.find(' ') + 1);
        });
        for (auto &str : logs)
        {
            if (!isalpha(str[str.size() - 1]))
            {
                result.push_back(str);
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 62/62 cases passed (16 ms)
//   √ Your runtime beats 91.57 % of cpp submissions
//   √ Your memory usage beats 32.5 % of cpp submissions (13.5 MB)