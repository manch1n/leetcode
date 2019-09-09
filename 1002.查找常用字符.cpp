/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<unordered_map<char, int>> maps;
        for (auto &str : A)
        {
            unordered_map<char, int> tmp;
            for (auto c : str)
            {
                tmp[c]++;
            }
            maps.push_back(std::move(tmp));
        }
        vector<string> result;
        for (auto &p : maps[0])
        {
            int min = p.second;
            bool flag = true;
            for (auto &map : maps)
            {
                unordered_map<char, int>::iterator i;
                if ((i = map.find(p.first)) != map.end())
                {
                    min = std::min(min, i->second);
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int i = 0; i < min; ++i)
                {
                    result.push_back(string(1, p.first));
                }
            }
        }
        return result;
    }
};

// √ Accepted
//   √ 83/83 cases passed (32 ms)
//   √ Your runtime beats 18.79 % of cpp submissions
//   √ Your memory usage beats 15.39 % of cpp submissions (12.7 MB)