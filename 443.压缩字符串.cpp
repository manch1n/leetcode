/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int count = 0;
        int size = chars.size();
        if (size <= 1)
            return size;
        for (auto p = chars.begin(), q = chars.begin(); q != chars.end();)
        {
            while (q != chars.end() && *q == *p)
            {
                q++;
            }
            int diff = q - p;
            if (diff == 1)
            {
                chars[count++] = *p;
            }
            else
            {
                chars[count++] = *p;
                auto num = to_string(diff);
                for (auto n : num)
                {
                    chars[count++] = n;
                }
            }
            p = q;
        }
        return count;
    }
};

//不知道是不是因为调用了string库的原因，有一些慢
// √ Accepted
//   √ 70/70 cases passed (20 ms)
//   √ Your runtime beats 52.47 % of cpp submissions
//   √ Your memory usage beats 75.61 % of cpp submissions (9.2 MB)