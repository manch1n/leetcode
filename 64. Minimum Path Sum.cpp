//link: https://leetcode-cn.com/problems/minimum-path-sum/submissions/
//leetcode include headers:
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int column=grid[0].size();
        for(int i=1;i<row;++i)
        {
            grid[i][0]+=grid[i-1][0];
        }
        for(int j=1;j<column;++j)
        {
            grid[0][j]+=grid[0][j-1];
        }
        for(int i=1;i<row;++i)  //dp[i,j]=grid[i,j]+min(grid[i-1,j],grid[i,j-1])
        {
            for(int j=1;j<column;++j)
            {
                grid[i][j]=std::min(grid[i-1][j],grid[i][j-1])+grid[i][j];
            }
        }
        return grid[row-1][column-1];
    }
};