/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */
#include <string>
using namespace std;
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {

            if (s[left] != s[right])
                return isPalind(s, left + 1, right) || isPalind(s, left, right - 1);
            left++;
            right--;
        }
        return true;
    }

    bool isPalind(string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return right;
    }
};
// √ Accepted
//   √ 460/460 cases passed (104 ms)
//   √ Your runtime beats 92.1 % of cpp submissions
//   √ Your memory usage beats 54.92 % of cpp submissions (26 MB)