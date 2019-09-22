/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    string defangIPaddr(string address)
    {
        string::size_type index = 0;
        while ((index = address.find('.', index)) != string::npos)
        {
            address.replace(address.begin() + index, address.begin() + index + 1, "[.]");
            index += 2;
        }
        return address;
    }
};

// √ Accepted
//   √ 62/62 cases passed (4 ms)
//   √ Your runtime beats 72.63 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (8.2 MB)