/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <string>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int ransom_size = ransomNote.size();
        int mag_size = magazine.size();
        if (ransom_size == 0)
            return true;
        if (mag_size == 0)
            return false;
        int bucket[26]{0};
        for (auto &c : magazine)
        {
            bucket[static_cast<int>(c) - 97]++;
        }
        for (auto &c : ransomNote)
        {
            if (--bucket[static_cast<int>(c) - 97] < 0)
                return false;
        }
        return true;
    }
};

// √ Accepted
//   √ 126/126 cases passed (24 ms)
//   √ Your runtime beats 96 % of cpp submissions
//   √ Your memory usage beats 82.67 % of cpp submissions (10.9 MB)