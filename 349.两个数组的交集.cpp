/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        if (size1 == 0 || size2 == 0)
            return vector<int>{};
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> vec;
        int i = 0, j = 0;
        while (i < size1 && j < size2)
        {
            if (nums1[i] < nums2[j])
                ++i;
            else if (nums1[i] == nums2[j])
            {
                if (find(vec.begin(), vec.end(), nums1[i]) == vec.end())
                {
                    vec.push_back(nums1[i]);
                }
                ++i;
                ++j;
            }
            else
                ++j;
        }
        return vec;
    }
};

// √ Accepted
//   √ 60/60 cases passed (16 ms)
//   √ Your runtime beats 87.23 % of cpp submissions
//   √ Your memory usage beats 76.68 % of cpp submissions (9 MB)