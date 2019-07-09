/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 到达终点
 */
#include <string>
using namespace std;
class Solution
{
public:
    bool rotateString(string A, string B)
    {
        int size = A.size();
        if (B.size() == 0)
        {
            return true;
        }
        if (size == 0)
        {
            return false;
        }
        while (size)
        {
            if (A == B)
            {
                return true;
            }
            A.push_back(A[0]);
            A.erase(A.begin());
            size--;
        }
        return false;
    }
};

// √ Accepted
//   √ 45/45 cases passed (4 ms)
//   √ Your runtime beats 85.04 % of cpp submissions
//   √ Your memory usage beats 78.65 % of cpp submissions (8.4 MB)