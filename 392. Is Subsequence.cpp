//link: https://leetcode-cn.com/problems/is-subsequence/submissions/
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
    bool isSubsequence(string s, string t) {
        int ssize=s.size();
        int tsize=t.size();
        int j=0;
        for(int i=0;i<ssize;++i)
        {
            for(;j<tsize;++j)
            {
                if(s[i]==t[j])
                {
                    ++j;
                    if(j==tsize&&i==ssize-1) return true;
                    break;
                }
            }
            if(j==tsize)
            {
                return false;
            }
        }
        return true;
    }
};