//link: https://leetcode-cn.com/problems/maximal-square/submissions/
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
    vector<int> transform(const vector<char>& vec)
    {
        vector<int> v;
        for(auto c:vec)
        {
            if(c=='1')
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
        }
        return v;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int max=0;
        if(matrix.size()==0)
        {
            return 0;
        }
        vector<int> preVec(matrix[0].size(),0);
        for(int i=0;i<matrix.size();++i)
        {
            auto curVec=transform(matrix[i]);
            for(int j=0;j<curVec.size();++j)
            {
                if(curVec[j]==1&&j!=0)
                {
                    curVec[j]=std::min({curVec[j-1],preVec[j],preVec[j-1]})+1;
                }
                max=std::max(curVec[j],max);
            }
            preVec=curVec;
        }
        return max*max;
    }
};