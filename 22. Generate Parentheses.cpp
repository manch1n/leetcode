//link: https://leetcode-cn.com/problems/generate-parentheses/submissions/
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
    int all;
    void generate(vector<string>& res,std::string pre,int used,int unmatched)
    {
        if(unmatched<0||used>all)
        {
            return;
        }
        else if(used==all&&unmatched==0)
        {
            res.push_back(pre);
            return;
        }
        //left
        {
            std::string tmp=pre;
            tmp.push_back('(');
            generate(res,tmp,used+1,unmatched+1);
        }
        //right
        {
            std::string tmp=pre;
            tmp.push_back(')');
            generate(res,tmp,used,unmatched-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        all=n;
        vector<string> res;
        generate(res,"",0,0);
        return res;
    }
};