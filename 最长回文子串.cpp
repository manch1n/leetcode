//link: https://leetcode-cn.com/problems/longest-palindromic-substring/
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
    string longestPalindrome(string s) {
        int size=s.size();
        std::string result;
        result.push_back(s[0]);
        //first case:
        for(int i=0;i<size;++i)
        {
            int prev=i-1,next=i+1;
            while(prev>=0&&next<size)
            {
                if(s[prev]==s[next])
                {
                    if((next-prev+1)>result.size())
                    {
                        result=std::string(s.begin()+prev,s.begin()+next+1);
                    }
                    prev--;
                    next++;
                }
                else
                {
                    break;
                }
            }  
        }
        //second case:
        for(int i=1;i<size;++i)
        {
            int prev=i-1,next=i;
            while(prev>=0&&next<size)
            {
                if(s[prev]==s[next])
                {
                    if(result.size()<(next-prev+1))
                    {
                        result=std::string(s.begin()+prev,s.begin()+next+1);
                    }
                    prev--;
                    next++;
                }
                else
                {
                    break;
                }
            }
        }
        
        return result;
    }
};

