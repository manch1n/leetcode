/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 */
/**
 * Definition for a binary tree node.*/
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val < L)
        {
            return trimBST(root->right, L, R);
        }
        if (root->val > R)
        {
            return trimBST(root->left, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

// √ Accepted
//   √ 77/77 cases passed (32 ms)
//   √ Your runtime beats 88.22 % of cpp submissions
//   √ Your memory usage beats 60.92 % of cpp submissions (21.6 MB)