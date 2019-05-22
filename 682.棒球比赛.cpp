/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int sum = 0;
        vector<int> res;
        int len = res.size();
        for (int i = 0; i < ops.size(); i++)
        {
            if (ops[i].compare("+") == 0)
            {
                res.push_back(res[res.size() - 1] + res[res.size() - 2]);
            }
            else if (ops[i].compare("D") == 0)
            {
                res.push_back(res[res.size() - 1] * 2);
            }
            else if (ops[i].compare("C") == 0)
            {
                res.pop_back();
            }
            else
            {
                res.push_back(stoi(ops[i]));
            }
        }
        for (int i = 0; i < res.size(); i++)
        {
            sum += res[i];
        }
        return sum;
    }
};
// √ Accepted
//   √ 39/39 cases passed (8 ms)
//   √ Your runtime beats 98.91 % of cpp submissions
//   √ Your memory usage beats 62.1 % of cpp submissions (9.5 MB)