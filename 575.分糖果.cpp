/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    using candi = int;
    using count = int;
    int distributeCandies(vector<int> &candies)
    {
        //这种做法其实比排序来讲多耗费了O（n）的空间。
        int size = candies.size();
        set<candi> s;
        for (auto n : candies)
        {
            s.insert(n);
        }
        int category = s.size();
        if (category >= size / 2)
        {
            return size / 2;
        }
        else
        {
            return category;
        }
    }
};

// √ Accepted
//   √ 205/205 cases passed (740 ms)
//   √ Your runtime beats 17.02 % of cpp submissions
//   √ Your memory usage beats 25.14 % of cpp submissions (54.8 MB)