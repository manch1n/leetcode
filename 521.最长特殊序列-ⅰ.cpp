/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */
#include <string>
using namespace std;
//这是什么鬼题哦
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a == b)
        {
            return -1;
        }
        int sizea = a.size();
        int sizeb = b.size();
        if (sizea > sizeb)
        {
            return sizea;
        }
        else if (sizea < sizeb)
        {
            return sizeb;
        }
        else
        {
            return sizea;
        }
    }
};

// √ Accepted
//   √ 41/41 cases passed (8 ms)
//   √ Your runtime beats 94.9 % of cpp submissions
//   √ Your memory usage beats 78.07 % of cpp submissions (8.3 MB)
