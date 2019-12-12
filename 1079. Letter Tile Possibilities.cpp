//link: https://leetcode-cn.com/problems/letter-tile-possibilities/submissions/
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
    void generate(int& res,vector<int> bucket,std::string pre)
    {
        for(int i=0;i<26;++i)
        {
            if(bucket[i]>0)  //i+65
            {
                pre.push_back(static_cast<char>(i+65));
                bucket[i]--;
                res++;
                generate(res,bucket,pre);
                //restore
                bucket[i]++;
                pre.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> bucket(26,0);
        for(auto c:tiles)
        {
            bucket[static_cast<int>(c)-65]++;
        }
        int res=0;
        generate(res,bucket,"");
        return res;
    }
};