//link: https://leetcode-cn.com/problems/triangle/
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
    int minimumTotal(vector<vector<int>>& triangle) {
        int height=triangle.size();
        for(int i=1;i<height;++i)
        {
            int len=triangle[i].size();                    //upper-right     upper-left
            for(int j=0;j<len;++j)    //triangle[i,j]+=min(triangle[i-1][j],triangle[i-1][j-1])
            {
                if(j==0)   
                {
                    triangle[i][j]+=triangle[i-1][j];
                }
                else if(j==len-1)
                {
                    triangle[i][j]+=triangle[i-1][j-1];
                }
                else
                {
                    triangle[i][j]+=std::min(triangle[i-1][j],triangle[i-1][j-1]);
                }
            }
        }
        return *std::min_element(std::begin(triangle[height-1]),std::end(triangle[height-1]));
    }
};