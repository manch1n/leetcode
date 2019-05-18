/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 */
/**
 * Definition for a binary tree node.*/
#include <unordered_map>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
public:
    unordered_map<int, int> m;
    void find(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return;
        }
        find(root->left, k);
        m[root->val] = k - root->val;
        find(root->right, k);
    }
    bool findTarget(TreeNode *root, int k)
    {
        find(root, k);
        for (auto &n : m)
        {
            if (m.find(n.second) != m.end() && *m.find(n.second) != n)
            {
                return true;
            }
        }
        return false;
    }
};

//emmm
// √ Accepted
//   √ 421/421 cases passed (112 ms)
//   √ Your runtime beats 16.92 % of cpp submissions
//   √ Your memory usage beats 11.06 % of cpp submissions (29.1 MB)