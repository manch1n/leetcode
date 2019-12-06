//link: https://leetcode-cn.com/problems/word-break/
//leetcode include headers:
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        unordered_set<string> wordsSet(wordDict.begin(),wordDict.end());
        dp[0]=true;                      //dp[i]means that the sub_string(0,i) can be segmented.
        for(int i=1;i<=s.size();++i)     //dp[i]=dp[j]==true and string(j,i) can be segmented.
        {
            if(wordsSet.find(s.substr(0,i))!=wordsSet.end())
            {
                dp[i]=true;
                continue;
            }
            for(int j=i;j>=1;--j)
            {
                if(dp[j]==true)
                {
                    if(wordsSet.find(s.substr(j,i-j))!=wordsSet.end())
                    {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()]==true;
    }
};