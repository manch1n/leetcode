/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    string filter(string email)
    {
        string result;
        bool atflag = false;
        bool addflag = false;
        for(auto c:email)
        {
            if(c=='@')
            {
                atflag = true;
                result.push_back('@');
                continue;
            }
            if(c=='+')
            {
                addflag = true;
                continue;
            }
            if(atflag)
            {
                result.push_back(c);
            }
            else
            {
                if(addflag)
                {
                    continue;
                }
                else
                {
                    if(c!='.')
                    {
                        result.push_back(c);
                    }
                }
            }
        }
        return result;
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto& str:emails)
        {
            s.insert(filter(str));
        }
        return s.size();
    }
};

// √ Accepted
//   √ 184/184 cases passed (32 ms)
//   √ Your runtime beats 93.07 % of cpp submissions
//   √ Your memory usage beats 70.24 % of cpp submissions (13.2 MB)