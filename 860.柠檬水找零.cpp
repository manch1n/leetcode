/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include <vector>
using namespace std;
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int bucket[3]{0};
        for (int pay : bills)
        {
            if (pay == 5)
            {
                bucket[0]++;
            }
            else if (pay == 10)
            {
                if (bucket[0])
                {
                    bucket[0]--;
                    bucket[1]++;
                }
                else
                {
                    return false;
                }
            }
            else if (pay == 20)
            {
                if (bucket[1])
                {
                    if (bucket[0])
                    {
                        bucket[0]--;
                        bucket[1]--;
                        bucket[2]++;
                    }
                    else
                        return false;
                }
                else
                {
                    if (bucket[0] < 3)
                    {
                        return false;
                    }
                    else
                    {
                        bucket[0] -= 3;
                        bucket[2]++;
                    }
                }
            }
        }
        return true;
    }
};
// √ Accepted
//   √ 45/45 cases passed (20 ms)
//   √ Your runtime beats 84.89 % of cpp submissions
//   √ Your memory usage beats 57.58 % of cpp submissions (9.7 MB)