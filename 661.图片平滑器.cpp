/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int step(int x,int y,string &where,vector<vector<int>> &map){//走路模拟
        if (where=="w") {
            ++x;
        }
        if (where=="s") {
            --x;
        }
        if (where=="d") {
            ++y;
        }
        if (where=="a") {
            --y;
        }
        if (where=="wa") {
            ++x;--y;
        }
        if (where=="wd") {
            ++x;++y;
        }
        if (where=="sa") {
            --x;--y;
        }
        if (where=="sd") {
            --x;++y;
        }
        if (where=="stop") {
            return map[x][y];
        }
        if (x>=0&&x<map.size()&&y>=0&&y<map[0].size()) {//移动合法
            return map[x][y];
        }
        return -1;
    }
    int avg_grayscale(int i,int j,vector<vector<int>> &map){//计算平均灰度
        vector<string> go{"w","s","a","d","wa","wd","sd","sa","stop"};//方向控制
        int sum=0,time=0,temp=0;
        for (string &v:go) {
            temp=step(i, j, v,map);
            if (temp!=-1) {
                sum+=temp;
                ++time;
            }
            
        }
        return sum/time;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row_max=M.size(),col_max=M[0].size();
        vector<int> line(col_max);//初始化行
        vector<vector<int>> ans(row_max,line);//由line初始化矩阵
        for (int i=0; i!=row_max; ++i) {//第i行（i纵向）
            for (int j=0;j!= col_max; ++j) {//第i行第j列（j横向）
                ans[i][j]=avg_grayscale(i, j, M);
            }
        }
        return ans;
    }
};

