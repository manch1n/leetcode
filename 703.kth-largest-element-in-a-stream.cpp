/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */
#include <vector>
#include <algorithm>
using namespace std;
class KthLargest
{
public:
    int _k;
    vector<int> n;
    KthLargest(int k, vector<int> &nums) : _k(k), n(nums)
    {
        std::sort(n.begin(), n.end());
    }

    int add(int val)
    {
        int i = 0;
        for (; i < n.size(); ++i)
        {
            if (n[i] >= val)
            {
                n.insert(n.begin() + i, val);
                break;
            }
        }
        if (i == n.size())
        {
            n.push_back(val);
        }
        int result = n[_k - 1];
        n.erase(n.begin() + _k - 1);
        return result;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
//不懂这道题要怎么确定第k大，加入，或者加入后删除返回的元素都不行。
// × Wrong Answer
//   × 1/10 cases passed (N/A)
//   × testcase: '["KthLargest","add","add","add","add","add"]\n[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
//   × answer: [null,4,5,5,8,4]
//   × expected_answer: [null,4,5,5,8,8]
//   × stdout: