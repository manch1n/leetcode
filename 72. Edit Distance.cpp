//link: https://leetcode-cn.com/problems/edit-distance/submissions/
//leetcode include headers:
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1);   //space complexity could be O(n)
        for(int i=0;i<word1.size()+1;++i)
        {
            dp[i].resize(word2.size()+1);
        } 
        for(int i=0;i<word2.size()+1;++i)
        {
            dp[0][i]=i;
        }
        for(int i=0;i<word1.size()+1;++i)
        {
            dp[i][0]=i;
        }
        for(int i=1;i<word1.size()+1;++i)
        {
            for(int j=1;j<word2.size()+1;++j)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j]=1+std::min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};