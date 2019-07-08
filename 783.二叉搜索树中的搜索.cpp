/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树中的搜索
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
    int min = INT_MAX;
    int prev = -1000000;
    int minDiffInBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        mids(root);
        return min;
    }
    void mids(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        mids(root->left);
        if (root->val - prev < min)
        {
            min = root->val - prev;
        }
        prev = root->val;
        mids(root->right);
    }
};
// √ Accepted
//   √ 45/45 cases passed (8 ms)
//   √ Your runtime beats 73.71 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (10.6 MB)
