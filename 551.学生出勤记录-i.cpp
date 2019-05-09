/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */
#include <string>
using namespace std;
class Solution
{
    //可以连续两个L
public:
    bool checkRecord(string s)
    {
        int Acount = 0;
        int Lflag = 0;
        for (auto c : s)
        {
            if (c == 'A')
            {
                Lflag = 0;
                Acount++;
                if (Acount == 2)
                {
                    return false;
                }
            }
            else if (c == 'L')
            {
                Lflag++;
                if (Lflag == 3)
                {
                    return false;
                }
            }
            else
                Lflag = 0;
        }
        return true;
    }
};

// √ Accepted
//   √ 113/113 cases passed (8 ms)
//   √ Your runtime beats 95.35 % of cpp submissions
//   √ Your memory usage beats 80.27 % of cpp submissions (8.5 MB)