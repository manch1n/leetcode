/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
    bool bst(TreeNode *root, int val)
    {
        if (root == nullptr)
            return true;
        bool left = bst(root->left, val);
        bool right = bst(root->right, val);
        return left && right && (root->val == val);
    }
    bool isUnivalTree(TreeNode *root)
    {
        return bst(root, root->val);
    }
};

// √ Accepted
//   √ 72/72 cases passed (4 ms)
//   √ Your runtime beats 85.41 % of cpp submissions
//   √ Your memory usage beats 77.94 % of cpp submissions (10.7 MB)