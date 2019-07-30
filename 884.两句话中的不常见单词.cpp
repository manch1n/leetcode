/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        map<string, int> A_store, B_store;
        string A_words, B_words;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != ' ')
            {
                A_words += A[i];
            }
            else
            {
                A_store[A_words]++;
                A_words.clear();
            }
        }
        A_store[A_words]++;
        A_words.clear();
        for (int i = 0; i < B.size(); i++)
        {
            if (B[i] != ' ')
            {
                B_words += B[i];
            }
            else
            {
                B_store[B_words]++;
                B_words.clear();
            }
        }
        B_store[B_words]++;
        B_words.clear();
        vector<string> result;
        for (auto i = A_store.begin(); i != A_store.end(); i++)
        {
            string tmp = i->first;
            int flag = 0;
            for (auto j = B_store.begin(); j != B_store.end(); j++)
            {
                if (j->first == tmp)
                    flag = 1;
            }
            if (flag == 1)
                continue;
            else
            {
                if (i->second == 1)
                    result.push_back(tmp);
            }
        }
        for (auto i = B_store.begin(); i != B_store.end(); i++)
        {
            string tmp = i->first;
            int flag = 0;
            for (auto j = A_store.begin(); j != A_store.end(); j++)
            {
                if (j->first == tmp)
                    flag = 1;
            }
            if (flag == 1)
                continue;
            else
            {
                if (i->second == 1)
                    result.push_back(tmp);
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 53/53 cases passed (4 ms)
//   √ Your runtime beats 89.97 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (8.7 MB)