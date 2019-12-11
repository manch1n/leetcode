//link: https://leetcode-cn.com/problems/permutations/submissions/
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
    void dfs(vector<vector<int>>& res,vector<int> pre,vector<int> remain)
    {
        if(remain.size()==0)
        {
            res.push_back(pre);
            return;
        }
        for(int i=0;i<remain.size();++i)
        {
            auto tmp=pre;
            tmp.push_back(remain[i]);
            auto rtmp=remain;
            rtmp.erase(rtmp.begin()+i);
            dfs(res,tmp,rtmp);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res,{},nums);
        return res;
    }
};