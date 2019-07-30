/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */
class Solution
{
public:
    int binaryGap(int N)
    {
        int base = 1;
        int later = 0, current = 0;
        bool flag = false;
        int i = 0;
        int max = 0;
        while (base <= N)
        {
            if (base & N)
            {
                if (flag == false)
                {
                    later = i;
                    flag = true;
                }
                else
                {
                    current = i;
                    if (current - later > max)
                    {
                        max = current - later;
                    }
                    later = current;
                }
            }
            i += 1;
            base = base << 1;
        }
        return max;
    }
};
// √ Accepted
//   √ 260/260 cases passed (8 ms)
//   √ Your runtime beats 52.72 % of cpp submissions
//   √ Your memory usage beats 69.44 % of cpp submissions (8.3 MB)