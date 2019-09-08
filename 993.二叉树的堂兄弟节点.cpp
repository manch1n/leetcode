/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    TreeNode *parx = nullptr;
    TreeNode *pary = nullptr;
    int depthx = 0;
    int depthy = 0;
    void findPar(TreeNode *root, int x, int y, int depth, TreeNode *par)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val == x)
        {
            parx = par;
            depthx = depth;
        }
        else if (root->val == y)
        {
            pary = par;
            depthy = depth;
        }
        findPar(root->left, x, y, depth + 1, root);
        findPar(root->right, x, y, depth + 1, root);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root == nullptr)
        {
            return false;
        }
        TreeNode *head = new TreeNode(-1);
        head->left = root;
        findPar(root, x, y, 0, head);
        return (parx != pary) && (depthx == depthy);
    }
};
// √ Accepted
//   √ 103/103 cases passed (8 ms)
//   √ Your runtime beats 61.82 % of cpp submissions
//   √ Your memory usage beats 92.36 % of cpp submissions (11 MB)