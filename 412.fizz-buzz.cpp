/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> Str_vec;
        if (n <= 0)
            return {};
        for (int i = 1; i <= n; ++i)
        {
            string tmp{to_string(i)};
            if (i % 3 == 0 && i % 5 == 0)
            {
                tmp = "FizzBuzz";
            }
            else if (i % 3 == 0)
            {
                tmp = "Fizz";
            }
            else if (i % 5 == 0)
            {
                tmp = "Buzz";
            }
            Str_vec.push_back(tmp);
        }
        return Str_vec;
    }
};

// √ Accepted
//   √ 8/8 cases passed (16 ms)
//   √ Your runtime beats 89.73 % of cpp submissions
//   √ Your memory usage beats 8.1 % of cpp submissions (10.6 MB)