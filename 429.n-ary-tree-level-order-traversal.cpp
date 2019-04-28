/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */
/*
// Definition for a Node.*/
#include <vector>
using namespace std;
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> Vvec_int{};
        vector<Node *> current{}, next{};
        if (root == nullptr)
            return {};
        current.push_back(root);
        while (current.empty() == false)
        {
            vector<int> Vec_int;
            for (auto &n : current)
            {
                Vec_int.push_back(n->val);
                if (n->children.size() != 0)
                {
                    next.insert(next.end(), n->children.begin(), n->children.end());
                }
            }
            Vvec_int.push_back(Vec_int);
            std::swap(current, next);
            next.clear();
        }
        return Vvec_int;
    }
};

// √ Accepted
//   √ 36/36 cases passed (240 ms)
//   √ Your runtime beats 72.35 % of cpp submissions
//   √ Your memory usage beats 40.62 % of cpp submissions (34 MB)