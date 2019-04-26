/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */
/**
 * Definition for a binary tree node.*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        if (l)
        {
            if (l->left == nullptr && l->right == nullptr)
            {
                return l->val + sumOfLeftLeaves(r);
            }
            else
            {
                return sumOfLeftLeaves(l) + sumOfLeftLeaves(r);
            }
        }
        else
        {
            return sumOfLeftLeaves(l) + sumOfLeftLeaves(r);
        }
    }
};
// √ Accepted
//   √ 102/102 cases passed (12 ms)
//   √ Your runtime beats 94 % of cpp submissions
//   √ Your memory usage beats 91.72 % of cpp submissions (13.3 MB)