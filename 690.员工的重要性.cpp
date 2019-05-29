/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */
/*
// Employee info*/
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// class Employee
// {
// public:
//     // It's the unique ID of each node.
//     // unique id of this employee
//     int id;
//     // the importance value of this employee
//     int importance;
//     // the id of direct subordinates
//     vector<int> subordinates;
// };

class Solution
{
public:
    //dfs
    map<int, Employee *> m;
    int importance = 0;
    void dfs(Employee *e)
    {
        importance += e->importance;
        for (auto s : e->subordinates)
        {
            dfs(m[s]);
        }
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        for (auto &e : employees)
        {
            m[e->id] = e;
        }
        dfs(m[id]);
        return importance;
    }
};

// √ Accepted
//   √ 108/108 cases passed (40 ms)
//   √ Your runtime beats 98.59 % of cpp submissions
//   √ Your memory usage beats 50 % of cpp submissions (15.3 MB)