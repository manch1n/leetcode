//link: https://leetcode-cn.com/problems/combination-sum-iii/submissions/
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
    int goal;

    void generate(vector<vector<int>>& res,vector<int>& pre,int start,int presum,int remain)
    {
        if(presum>goal||remain<0||start<0)
        {
            return;
        }
        if(presum==goal&&remain==0)
        {
            res.push_back(pre);
            return;
        }
        for(int i=start;i>=1;--i)
        {
            pre.push_back(i);
            generate(res,pre,i-1,presum+i,remain-1);
            pre.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        goal=n;
        vector<vector<int>> res;
        vector<int> tmp;
        generate(res,tmp,9,0,k);
        return res;
    }
};