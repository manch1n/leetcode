//link: https://leetcode-cn.com/problems/unique-paths-ii/submissions/
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long long> prev;
        int row=obstacleGrid.size();
        int column=obstacleGrid[0].size();
        prev.resize(column);
        prev[0]=1;
        for(int i=0;i<row;++i)
        {
            vector<long long> current;
            current.resize(column);
            for(int j=0;j<column;++j)
            {
                if(obstacleGrid[i][j]==1)
                {
                    current[j]=0;
                }
                else
                {
                    if(j==0)
                    {
                        current[j]+=prev[j];
                    }
                    else
                    {
                        current[j]+=prev[j]+current[j-1];
                    }
                }
            }
            prev=current;
        }
        return prev[column-1];
    }
};