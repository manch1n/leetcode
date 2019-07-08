/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 二叉搜索树中的插入操作
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<int> alpha_index;
        for (int i = 0; i < S.size(); ++i)
        {
            if (isalpha(S[i]))
            {
                alpha_index.push_back(i);
            }
        }
        vector<string> result;
        transform(S.begin(), S.end(), S.begin(), ::tolower);
        int times = pow(2, alpha_index.size());
        result.push_back(S);
        for (int i = 1; i < times; ++i)
        {
            string tmp(S);
            int sig = 1;
            int j = 0;
            int index = 0;
            while (sig <= i)
            {
                if (sig & i)
                {
                    tmp[alpha_index[index]] = toupper(S[alpha_index[index]]);
                }
                sig = sig << 1;
                index++;
            }
            result.push_back(tmp);
        }
        return result;
    }
};
// √ Accepted
//   √ 63/63 cases passed (16 ms)
//   √ Your runtime beats 84.87 % of cpp submissions
//   √ Your memory usage beats 93.95 % of cpp submissions (11.9 MB)