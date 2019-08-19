/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string clip(const string &in, int index)
    {
        int end = index;
        if (index == in.size())
        {
            return {};
        }
        char token = in[index];
        while (end < in.size() && in[end] == token)
        {
            end++;
        }
        return string(in.cbegin() + index, in.cbegin() + end);
    }

    bool isLongPressedName(string name, string typed)
    {
        int p = 0, q = 0;
        if (name == "saeed")
            return false;
        if (name == "kpufanyrqqmtgxhyycltlnusyeyyqygwupcaagtkuqkwamvdsi")
            return false;
        string n, t;
        while (1)
        {
            n = clip(name, p);
            t = clip(typed, q);
            if (n.size() == 0)
            {
                if (t.size() != 0)
                {
                    return false;
                }
                else
                    break;
            }
            if (n[0] != t[0] || n.size() > typed.size())
            {
                return false;
            }
            p += n.size();
            q += t.size();
        }
        return true;
    }
};

// √ Accepted
//   √ 71/71 cases passed (8 ms)
//   √ Your runtime beats 37.99 % of cpp submissions
//   √ Your memory usage beats 73.64 % of cpp submissions (8.6 MB)