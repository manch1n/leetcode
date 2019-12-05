//link: https://leetcode-cn.com/problems/coin-change/submissions/
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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (const int &it : coins) {  //dp[i]=min(dp[i-j]+1)
            if (it <= amount) dp[it] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            for (const int &it : coins) {
                int t = i - it;
                if (t <= 0) continue;
                if (dp[i] == -1 && dp[t] != -1)
                    dp[i] = dp[t] + 1;
                else if (dp[t] != -1) 
                    dp[i] = min(dp[t] + 1, dp[i]);
            }
        }
        return dp[amount];
    }
};