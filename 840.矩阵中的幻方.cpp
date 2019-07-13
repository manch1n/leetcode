/*
 * @lc app=leetcode.cn id=840 lang=cpp
 *
 * [840] 矩阵中的幻方
 */
#include <vector>
using namespace std;
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
                int nRow = grid.size();
        if(nRow < 3) return 0;
        int nCol = grid[0].size();
        if(nCol < 3) return 0;
        int nRes = 0;
        for(int i=0;i<nRow-2;i++)
        {
            for(int j=0;j<nCol-2;j++)
            {
                if(grid[i+1][j+1] != 5 || grid[i][j] == 5)
                    continue;
                if(islogic(grid,i+2,j+2))
                    nRes++;
            }
        }
        return nRes;
    }
    
    bool islogic(vector<vector<int>>& grid,int row,int col)
    {
        int nSum = grid[row-2][col-2]+grid[row-2][col-1]+grid[row-2][col];
        for(int i=row-2;i<= row;i++)
        {
            int temp = 0;
            for(int j=col-2;j<=col;j++)
            {
                if(grid[i][j]  < 1 || grid[i][j] > 9)
                    return false;
                temp += grid[i][j];
            }
            if(temp != nSum) return false;
        }
        for(int j=col-2;j<=col;j++)
        {
            int temp = 0;
            for(int i=row-2;i<= row;i++)
            {
                temp += grid[i][j];
            }
            if(temp != nSum) return false;
        }
        if(grid[row-2][col-2]+grid[row-1][col-1]+grid[row][col] != nSum
          || grid[row-2][col]+grid[row-1][col-1]+grid[row][col-2] != nSum)
            return false;
        return true;
    }
};

