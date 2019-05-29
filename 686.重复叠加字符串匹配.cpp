/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 */
#include <string>
using namespace std;
class Solution
{
public:
    int repeatedStringMatch(string A, string B)
    {
        string tmp(A);
        int result = 1;
        bool isBigger = false;
        do
        {
            if (A.find(B) != string::npos)
            {
                return result;
            }
            result += 1;
            A += tmp;
        } while (A.size() < B.size());
        return -1;
    }
};

//有点恶心人。
// × Wrong Answer
//   × 49/55 cases passed (N/A)
//   × testcase: '"aaaaaaaaaaaaaaaaaaaaaab"\n"ba"'
//   × answer: -1
//   × expected_answer: 2
//   × stdout:
