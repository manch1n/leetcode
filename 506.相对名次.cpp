/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        //O(nlogn)的时间与O（N）的空间
        vector<int> tmp(nums);
        map<int, int, std::greater<int>> m;  //成绩与索引
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            m[nums[i]] = i;
        }
        int count=0;
        vector<string> result(size);
        for (auto i = m.begin(); i != m.end(); ++i)
        {
            if(count>=3)
            {
                result[i->second]=to_string(count+1);
            }
            else if(count==0)
            {
                result[i->second]="Gold Medal";
            }
            else if(count==1)
            {
                result[i->second]="Silver Medal";
            }
            else if(count==2)
            {
                result[i->second]="Bronze Medal";
            }
            count++;
        }
        return result;
    }
};

//有点惨，原来我忽略了map是一个优先队列
// √ Accepted
//   √ 17/17 cases passed (64 ms)
//   √ Your runtime beats 24.43 % of cpp submissions
//   √ Your memory usage beats 9.09 % of cpp submissions (13.3 MB)

// √ Accepted
//   √ 17/17 cases passed (32 ms)
//   √ Your runtime beats 87.33 % of cpp submissions
//   √ Your memory usage beats 19.01 % of cpp submissions (12.3 MB)