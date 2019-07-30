/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
       vector<pair<int,int>> dire={{0,1},{1,0},{0,-1},{-1,0}};
       set<pair<int,int>> ob;
       int i=0,x=0,y=0,maxdis=0;
       for(vector<int> vi:obstacles){
           ob.insert(make_pair(vi[0],vi[1]));
       }
       for(int cd:commands){
           if(cd==-2){//左转
               i=(i+3)%4;
           }else if(cd==-1){//右转
               i=(i+1)%4;
           }else{//在某一个方向上对x或者对y更改
               while(cd){
                   int dx=x+dire[i].first;
                   int dy=y+dire[i].second;
                   if(ob.find(make_pair(dx,dy))==ob.end()){//没有障碍物则更新x和y
                      x=dx;
                      y=dy;
                     maxdis=max(maxdis,x*x+y*y);
                    }else{
                      break;
                   }
                   --cd;
               }
           }
       }
     
      return  maxdis;
    }
};


// √ Accepted
//   √ 47/47 cases passed (132 ms)
//   √ Your runtime beats 87.27 % of cpp submissions
//   √ Your memory usage beats 52.05 % of cpp submissions (27 MB)