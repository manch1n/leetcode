/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include <string>
using namespace std;
class Solution
{
public:
    inline bool if_upper(char c)
    {
        if (c >= 65 && c <= 90)
            return true;
        else
            return false;
    }

    int longestPalindrome(string s)
    {
        int size = s.size();
        if (size <= 1)
            return size;
        int bucket_upper[26]{0};
        int bucket_smaller[26]{0};
        for (auto &c : s)
        {
            if (if_upper(c))
            {
                bucket_upper[static_cast<int>(c) - 65]++;
            }
            else
            {
                bucket_smaller[static_cast<int>(c) - 97]++;
            }
        }
        bool singular = false;
        int count = 0;
        for (auto i = begin(bucket_upper); i != end(bucket_upper); ++i)
        {
            count += *i / 2 * 2;
            if (singular)
                continue;
            if (*i % 2)
                singular = true;
        }
        for (auto i = begin(bucket_smaller); i != end(bucket_smaller); ++i)
        {
            count += *i / 2 * 2;
            if (singular)
                continue;
            if (*i % 2)
                singular = true;
        }
        if (singular)
            count += 1;
        return count;
    }
};

// √ Accepted
//   √ 95/95 cases passed (8 ms)
//   √ Your runtime beats 97.79 % of cpp submissions
//   √ Your memory usage beats 81.94 % of cpp submissions (8.8 MB)