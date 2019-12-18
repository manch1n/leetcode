//link: https://leetcode-cn.com/problems/combination-sum-ii/
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
    int targetSum;
    int preVisit=-1;
    void generate(vector<vector<int>>& res,const vector<int>& candidates,vector<int>& pre,int preSum,int start)
    {
        if(start>candidates.size()||preSum>targetSum)
        {
            return;
        }
        else if(preSum==targetSum)
        {
            res.push_back(pre);
            return;
        }
        for(int i=start;i<candidates.size();++i)
        {
            if(candidates[i]==preVisit)
            {
                continue;
            }
            pre.push_back(candidates[i]);
            generate(res,candidates,pre,preSum+candidates[i],i+1);
            pre.pop_back();
            preVisit=candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        targetSum=target;
        generate(res,candidates,tmp,0,0);
        return res;
    }
};