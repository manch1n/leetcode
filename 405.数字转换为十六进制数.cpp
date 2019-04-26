/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */
#include <string>
using namespace std;
class Solution
{
public:
    int bit_num(int num)
    {
        if (num < 0)
        {
            return 32;
        }
        int base = 1;
        int count = 0;
        for (int i = 0; i < 31; i++)
        {
            if (num <= base - 1)
                break;
            count++;
            base = base << 1;
        }
        return count;
    }

    string toHex(int num)
    {
        string result;
        int bit = bit_num(num);
        int basei = 1;
        int basej = 1;
        for (int i = 0; i < 8; ++i)
        {
            int tmp = 0;
            for (int j = 0; j < 4; ++j)
            {
                if (num & basei)
                {
                    tmp += basej;
                }
                if (i == 7 && j == 3)
                    continue;
                basei = basei << 1;
                basej = basej << 1;
            }
            if (tmp < 10)
            {
                result.insert(result.begin(), static_cast<char>(tmp + 48));
            }
            else
            {
                result.insert(result.begin(), static_cast<char>(tmp + 87));
            }
            basej = 1;
            if (bit <= (i + 1) * 4)
                break;
        }
        return result;
    }
};

// √ Accepted
//   √ 100/100 cases passed (8 ms)
//   √ Your runtime beats 88.8 % of cpp submissions
//   √ Your memory usage beats 75.7 % of cpp submissions (8.1 MB)