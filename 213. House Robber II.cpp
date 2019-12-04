//link: https://leetcode-cn.com/problems/house-robber-ii/
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
    int rob(vector<int>& nums) {  //dp[i]=max(dp[i-1],dp[i-2]+nums[i])
        if(nums.size()==1) return nums[0];
        else if(nums.size()==0) return 0;
        int ppre=0;
        int pre=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            int cur=std::max(pre,ppre+nums[i]);
            ppre=pre;
            pre=cur;
        }
        int max1=pre;

        ppre=0;
        pre=0;
        for(int i=1;i<nums.size();++i)
        {
            int cur=std::max(pre,ppre+nums[i]);
            ppre=pre;
            pre=cur;
        }
        int max2=pre;
        return std::max(max2,max1);
    }
};