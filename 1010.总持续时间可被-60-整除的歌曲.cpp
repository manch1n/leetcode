/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        int count=0, rem[60] = {0};
        for(int i=0; i<time.size(); i++){
            int index = time[i]%60;
            count += rem[(60-index)%60];
            rem[index]++;
        }
        return count;
    }
};

// √ Accepted
//   √ 34/34 cases passed (64 ms)
//   √ Your runtime beats 28.23 % of cpp submissions
//   √ Your memory usage beats 65.09 % of cpp submissions (11.6 MB)