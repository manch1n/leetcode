/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int get_length(int val)
    {
        int length = 0;
        if (val == 0)
            return -1;
        while (val)
        {
            if (val % 10 == 0)
                return -1;
            val /= 10;
            length++;
        }
        return length;
    }
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (int i = left; i <= right; i++)
        {
            int length = get_length(i);
            if (length == -1)
                ;
            else
            {
                int j;
                int data = i;
                for (j = 0; j < length; j++)
                {
                    int temp = data % 10;
                    if (i % temp != 0)
                        break;
                    data /= 10;
                }
                if (j == length)
                    res.push_back(i);
            }
        }
        return res;
    }
};

// √ Accepted
//   √ 31 / 31 cases passed(8 ms)
//   √ Your runtime beats 85.99 % of cpp submissions
//   √ Your memory usage beats 54.89 % of cpp submissions(8.5 MB)
