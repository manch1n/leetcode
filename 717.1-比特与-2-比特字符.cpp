/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */
#include <vector>
using namespace std;
class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int size = bits.size();
        if (bits[size - 1] == 1)
        {
            return false;
        }
        if (size == 1)
        {
            return true;
        }
        for (int i = 0; i < size; ++i)
        {
            if (bits[i] == 1)
            {
                if (i == size - 2)
                {
                    return false;
                }
                i += 1;
            }
        }
        return true;
    }
};
// √ Accepted
//   √ 93/93 cases passed (4 ms)
//   √ Your runtime beats 98.99 % of cpp submissions
//   √ Your memory usage beats 77.32 % of cpp submissions (8.7 MB)
