//link: https://leetcode-cn.com/problems/palindrome-partitioning/submissions/
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
    bool isPalindrome(const std::string& s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }

    void generate(vector<vector<string>>& res,vector<string>& pre,string& str,int start)
    {
        if(start==str.size())
        {
            res.push_back(pre);
        }
        for(int i=start;i<str.size();++i)
        {
            if(isPalindrome(str,start,i))
            {
                pre.push_back(str.substr(start,i-start+1));
                generate(res,pre,str,i+1);
                pre.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        generate(res,tmp,s,0);
        return res;
    }
};