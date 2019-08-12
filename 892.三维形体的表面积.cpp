/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
                int i,j,number;
        int sum=0,num = 0;
        for(i=0;i<grid.size();i++)
        {
            for(j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    sum = sum+grid[i][j];
                }
                if(grid[i][j]>1)
                {
                    num = num+grid[i][j]-1;
                }
                if(i+1 < grid[0].size() && grid[i+1][j] != 0) //下
                {
                    num = num+min(grid[i][j],grid[i+1][j]);
                }
                 if(j+1 < grid.size() && grid[i][j+1] != 0)   //右
                {
                    num = num+min(grid[i][j],grid[i][j+1]);
                }
            }
        }
        number = sum*6-num*2;
        return number;
    }
};

// √ Accepted
//   √ 90/90 cases passed (20 ms)
//   √ Your runtime beats 21.34 % of cpp submissions
//   √ Your memory usage beats 80.6 % of cpp submissions (9.3 MB)