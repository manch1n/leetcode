/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int i_1 = numeric_limits<int>::min(), i_2 = numeric_limits<int>::min(), i_3 = numeric_limits<int>::min();
    int count = 0;
    bool flag=true;
    inline int max_3(int num)
    {
        if(num==numeric_limits<int>::min())
        {
            if(flag)
            {
                flag=false;
                count++;
            }
        }
        if (num == i_1 || num == i_2 || num == i_3)
        {
            return i_3;
        }
        if (num >= i_1)
        {
            i_3 = i_2;
            i_2 = i_1;
            i_1 = num;
            count++;
        }
        else if (num >= i_2)
        {
            i_3 = i_2;
            i_2 = num;
            count++;
        }
        else if (num >= i_3)
        {
            i_3 = num;
            count++;
        }
        return i_3;
    }

    int thirdMax(vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 2)
        {
            return *max_element(nums.begin(), nums.end());
        }
        for (int i = 0; i < size; ++i)
        {
            max_3(nums[i]);
        }
        if(count<3)
        {
            return i_1;
        }
        return i_3;
    }
};


// √ Accepted
//   √ 26/26 cases passed (12 ms)
//   √ Your runtime beats 97.39 % of cpp submissions
//   √ Your memory usage beats 85.78 % of cpp submissions (9 MB)