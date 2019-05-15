/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int indexSum = INT_MAX;
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size();++i)
        {
            m[list1[i]] = i;
        }
        vector<string> result;
        for (int i = 0; i < list2.size();++i)
        {
            if(m.find(list2[i])!=m.end())
            {
                if(i+m[list2[i]]<indexSum)
                {
                    indexSum = i + m[list2[i]];
                    result.clear();
                    result.push_back(list2[i]);
                }
                else if(i+m[list2[i]]==indexSum)
                {
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 133/133 cases passed (144 ms)
//   √ Your runtime beats 80 % of cpp submissions
//   √ Your memory usage beats 67.37 % of cpp submissions (28.2 MB)
