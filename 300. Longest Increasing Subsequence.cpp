//link: https://leetcode-cn.com/problems/longest-increasing-subsequence/submissions/
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
    int lengthOfLIS(vector<int>& nums) {  //dp[i] means that the longest length of the array that end of n[i]
    //dp[i]=min(max[j])+1 j<i and n[i]>n[j]
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size(),1);
        int result=1;
        for(int i=1;i<nums.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=std::max(dp[j]+1,dp[i]);
                }
                result=std::max(dp[i],result);
            }
        }
        return result;
    }
};