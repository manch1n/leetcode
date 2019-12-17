//link: https://leetcode-cn.com/problems/combination-sum/
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
    void generate(vector<vector<int>>& res,vector<int>& pre,const vector<int>& candidates,int preSum,int start)
    {
        if(preSum==targetSum)
        {
            res.push_back(pre);
        }
        else if(preSum>targetSum)
        {
            return;
        }
        for(int i=start;i<candidates.size();++i)
        {
            pre.push_back(candidates[i]);
            generate(res,pre,candidates,preSum+candidates[i],i);
            pre.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        targetSum=target;
        vector<vector<int>> res;
        vector<int> tmp;
        generate(res,tmp,candidates,0,0);
        return res;
    }
};