/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> s;
        for (auto c : S)
        {
            if (c == '#')
            {
                if (s.empty() == true)
                {
                    continue;
                }
                else
                {
                    s.pop();
                }
            }
            else
            {
                s.push(c);
            }
        }

        stack<char> t;
        for (auto c : T)
        {
            if (c == '#')
            {
                if (t.empty() == true)
                {
                    continue;
                }
                else
                {
                    t.pop();
                }
            }
            else
            {
                t.push(c);
            }
        }
        if (s == t)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// √ Accepted
//   √ 104/104 cases passed (8 ms)
//   √ Your runtime beats 59.8 % of cpp submissions
//   √ Your memory usage beats 87.65 % of cpp submissions (8.4 MB)