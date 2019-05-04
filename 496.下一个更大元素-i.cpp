/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include <vector>
#include <stack>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        //二叉查找？？？O（n2）我还是直接用find好了
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 == 0)
            return vector<int>{};
        vector<int> result{};
        // for(auto n:nums1)
        // {
        //     auto i=find(nums2.begin(),nums2.end(),n);
        //     ++i;
        //     for(;i!=nums2.end();++i)
        //     {
        //         if(*i>n)
        //         result.push_back(*i);
        //     }
        //     if(i==nums2.end());
        //     result.push_back(-1);
        // }
        // return result;

        stack<int> s;
        map<int, int> m;
        for (int i = 0; i < nums2.size(); i++)
        {
            while (!s.empty() && s.top() < nums2[i]) //判断是否非栈空且s.top()小于nums[i]
            {                                        //在上述条件满足的情况下，不断修改栈顶的映射并把栈顶pop出栈
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]); //最后将nums[i]push到栈中
        }

        vector<int> v; //创建要返回的数组
        for (int i = 0; i < nums1.size(); i++)
        {
            if (m[nums1[i]] == 0) // 如果映射是0，-1入栈
                v.push_back(-1);
            else
                v.push_back(m[nums1[i]]); //如果映射不是0，把映射入栈
        }
        return v;
    }
};

// × Output Limit Exceeded
//   × 3/17 cases passed (N/A)
// √ Accepted
//   √ 17/17 cases passed (20 ms)
//   √ Your runtime beats 89.86 % of cpp submissions
//   √ Your memory usage beats 26.18 % of cpp submissions (9.5 MB)