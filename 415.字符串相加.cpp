/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

#include <string>
using namespace std;
class Solution
{
public:
    inline int ctoi(char c)
    {
        return static_cast<int>(c) - 48;
    }

    inline char itoc(int num)
    {
        return static_cast<char>(num + 48);
    }

    string addStrings(string num1, string num2)
    {
        string result{};
        int size1 = num1.size();
        int size2 = num2.size();
        if (size1 == 0)
            return num2;
        if (size2 == 0)
            return num1;
        int carry = 0;
        for (int i = size1 - 1, j = size2 - 1; i >= 0 && j >= 0; --i, --j)
        {
            int tmp = ctoi(num1[i]) + ctoi(num2[j]);
            if (carry)
            {
                tmp += 1;
                carry = 0;
            }
            if (tmp >= 10)
            {
                result.insert(result.begin(), itoc(tmp - 10));
                carry = 1;
            }
            else
            {
                result.insert(result.begin(), itoc(tmp));
            }
        }
        if (size1 < size2)
            std::swap(num1, num2);
        int diff = num1.size() - num2.size() - 1;
        while (diff >= 0)
        {
            int tmp = ctoi(num1[diff]);
            if (carry)
            {
                tmp += 1;
            }
            if (tmp >= 10)
            {
                result.insert(result.begin(), itoc(tmp - 10));
            }
            else
            {
                result.insert(result.begin(), itoc(tmp));
                carry = 0;
            }

            --diff;
        }
        if (carry)
        {
            result.insert(result.begin(), '1');
        }
        if (result.size() == 0)
            return "0";
        return result;
    }
};

// √ Accepted
//   √ 315/315 cases passed (28 ms)
//   √ Your runtime beats 48.31 % of cpp submissions
//   √ Your memory usage beats 74.07 % of cpp submissions (9.2 MB)