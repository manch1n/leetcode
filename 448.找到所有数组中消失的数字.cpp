/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include <vector>
#include <memory>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // int size=nums.size();
        // if(size==0) return {};
        // vector<int> result;
        // shared_ptr<vector<bool>> SP_b=make_shared<vector<bool>>(size+1,false);
        // for(auto n:nums)
        // {
        //     (*SP_b)[n]=true;
        // }
        // for(int i=1;i<=size;++i)
        // {
        //     if((*SP_b)[i]==false)
        //     {
        //         result.push_back(i);
        //     }
        // }
        // return result;
        // //标记法emmm
        int size=nums.size();
        if(size==0) return {};
        vector<int> result;
        for(int i=0;i<size;++i)
        {
            int index=abs(nums[i])-1;
            nums[index]=nums[index]>0?-nums[index]:nums[index];  //把访问过的元素标记置负。
        }
        for(int i=0;i<size;++i)
        {
            if(nums[i]>0)
            {
                result.push_back(i+1);
            }
        }
        return result;
    }
};


//O（1）的空间又要O（n）的时间，有点想不出来。
// √ Accepted
//   √ 34/34 cases passed (160 ms)
//   √ Your runtime beats 54.87 % of cpp submissions
//   √ Your memory usage beats 19.12 % of cpp submissions (15.2 MB)