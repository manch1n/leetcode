/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int sum = 0;
    void bst(TreeNode *root, int l, int r)
    {
        if (root == nullptr)
        {
            return;
        }
        bst(root->left, l, r);
        if (root->val >= l && root->val <= r)
        {
            sum += root->val;
        }
        bst(root->right, l, r);
    }
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        bst(root, L, R);
        return sum;
    }
};

// √ Accepted
//   √ 42/42 cases passed (172 ms)
//   √ Your runtime beats 92.94 % of cpp submissions
//   √ Your memory usage beats 86.72 % of cpp submissions (41.1 MB)