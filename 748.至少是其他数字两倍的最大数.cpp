/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 至少是其他数字两倍的最大数
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    //有点无聊
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        vector<int> tar(26, 0);
        for (char c : licensePlate)
        {
            c = tolower(c);
            if (c >= 'a' && c <= 'z')
                tar[c - 'a']++;
        }

        int minLen = INT_MAX;
        string res = "";
        for (string one : words)
        {
            if (isValid(tar, one) == true)
            {
                if (one.length() < minLen)
                {
                    minLen = one.length();
                    res = one;
                }
            }
        }
        return res;
    }

    bool isValid(vector<int> &tar, string s)
    {
        vector<int> mmp(26, 0);
        for (char c : s)
        {
            c = tolower(c);
            if (c >= 'a' && c <= 'z')
                mmp[c - 'a']++;
        }
        for (int i = 0; i < mmp.size(); i++)
        {
            if (tar[i] != 0 && mmp[i] < tar[i])
                return false;
        }
        return true;
    }
};
// √ Accepted
//   √ 102/102 cases passed (40 ms)
//   √ Your runtime beats 49.75 % of cpp submissions
//   √ Your memory usage beats 50 % of cpp submissions (14.6 MB)