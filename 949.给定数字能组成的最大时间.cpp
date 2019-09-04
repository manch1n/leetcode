/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 给定数字能组成的最大时间
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        // string result;
        // //hour0:0-2
        // int tempMax = -1;
        // bool flag[4] = {false};
        // int index = -1;
        // for (int i = 0; i < 4; ++i)
        // {
        //     if (A[i] <= 2 && flag[i] == false)
        //     {
        //         if (A[i] > tempMax)
        //         {
        //             tempMax = A[i];
        //             index = i;
        //         }
        //     }
        // }
        // if (tempMax == -1)
        //     return {};
        // else
        // {
        //     flag[index] = true;
        //     result.push_back(tempMax + 48);
        // }
        // tempMax = -1;
        // //hour1:0-4
        // int upbound;
        // upbound = result[0] == '2' ? 3 : 9;
        // for (int i = 0; i < 4; ++i)
        // {
        //     if (A[i] <= upbound && flag[i] == false)
        //     {
        //         if (A[i] > tempMax)
        //         {
        //             tempMax = A[i];
        //             index = i;
        //         }
        //     }
        // }
        // if (tempMax == -1)
        //     return {};
        // else
        // {
        //     flag[index] = true;
        //     result.push_back(tempMax + 48);
        //     result.push_back(':');
        // }
        // tempMax = -1;
        // //minute0:0-5
        // for (int i = 0; i < 4; ++i)
        // {
        //     if (A[i] <= 5 && flag[i] == false)
        //     {
        //         if (A[i] > tempMax)
        //         {
        //             tempMax = A[i];
        //             index = i;
        //         }
        //     }
        // }
        // if (tempMax == -1)
        //     return {};
        // else
        // {
        //     flag[index] = true;
        //     result.push_back(tempMax + 48);
        // }
        // tempMax = -1;
        // //minute1:0-9
        // for (int i = 0; i < 4; ++i)
        // {
        //     if (!flag[i])
        //     {
        //         result.push_back(A[i] + 48);
        //     }
        // }
        // return result;

        sort(A.begin(), A.end());
        string answer = "";

        for (int t = 2399; t >= 0; --t)
        {
            if (t % 100 >= 60) //分钟大于60的排除
                continue;

            vector<int> digits;
            int t_copy = t;

            for (int i = 0; i < 4; i++)
            {
                digits.push_back(t_copy % 10);
                t_copy /= 10;
            }

            sort(digits.begin(), digits.end());

            if (A == digits)
            {
                char str[100];
                sprintf(str, "%02d:%02d", t / 100, t % 100);
                answer = str;
                return answer;
            }
        }

        return answer;
    }
};
// × Wrong Answer
//   × 169/172 cases passed (N/A)
//   × testcase: '[2,0,6,6]'
//   × answer: ""
//   × expected_answer: "06:26"
//   × stdout:

// √ Accepted
//   √ 172/172 cases passed (156 ms)
//   √ Your runtime beats 5.67 % of cpp submissions
//   √ Your memory usage beats 6.67 % of cpp submissions (25.1 MB)