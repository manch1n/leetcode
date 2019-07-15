/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.size() == 0)
        {
            return false;
        }
        if (A.size() != B.size())
            return false;
        if (A.size() == 2)
        {
            string tmp(A);
            std::reverse(tmp.begin(), tmp.end());
            if (tmp == B)
            {
                return true;
            }
            else
                return false;
        }
        int size = A.size();
        char a, b;
        int index1, index2;
        int flag = 0;
        for (int i = 0; i < size; ++i)
        {
            if (A[i] != B[i])
            {
                if (flag == 0)
                {
                    a = B[i];
                    index1 = i;
                    flag++;
                }
                else if (flag == 1)
                {
                    b = B[i];
                    index2 = i;
                    flag++;
                }
                else
                    return false;
            }
        }
        if (flag == 0)
        {
            return true;
        }
        if (A[index1] == b && A[index2] == a)
        {
            return true;
        }
        else
            return false;
    }
};

// × Wrong Answer
//   × 22/23 cases passed (N/A)
//   × testcase: '"abcd"\n"abcd"'
//   × answer: true
//   × expected_answer: false
//   × stdout: