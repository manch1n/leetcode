//link: https://leetcode-cn.com/problems/maximum-subarray/submissions/
//leetcode include headers:
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=nums[0];
        int pre=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();++i)   //dp[i]=max(dp[i-1]+n[i],n[i])
        {
            cur=std::max(pre+nums[i],nums[i]);
            result=std::max(cur,result);
            pre=cur;
        }
        return result;
    }
};