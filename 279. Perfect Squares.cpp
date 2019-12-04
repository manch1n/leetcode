//link: https://leetcode-cn.com/problems/perfect-squares/submissions/
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
    // int roundDown(int n)
    // {
    //     long long i=1;
    //     for(;i*i<=n;i++)
    //     {
    //     }
    //     return (i-1)*(i-1);
    // }
    // int numSquares(int n) {
    //     int result=0;
    //     while(n)
    //     {
    //         n-=roundDown(n);
    //         result++;
    //     }
    //     return result;
    // }
    int numSquares(int n) {   //dp[i]=min(i,dp[i-j*j])
        vector<int> dp(n+1);
        for(int i=1;i<=n;++i)
        {
            dp[i]=i;
            for(int j=1;i-j*j>=0;++j)
            {
                dp[i]=std::min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};