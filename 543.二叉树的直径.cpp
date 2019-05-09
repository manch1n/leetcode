/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    //每个节点遍历一次左右高度？？然后依次遍历下去？？？
    int len(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = len(root->left) + 1;
        int r = len(root->right) + 1;
        return l > r ? l : r;
    }
    int max = 0;
    void prev(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        int left_max = len(root->left);
        int right_max = len(root->right);
        int result = left_max + right_max + 1;
        if (result > max)
        {
            max = result;
        }
        prev(root->left);
        prev(root->right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        prev(root);
        return max - 1;
    }
};

// √ Accepted
//   √ 106/106 cases passed (36 ms)
//   √ Your runtime beats 51.87 % of cpp submissions
//   √ Your memory usage beats 85.78 % of cpp submissions (19.7 MB)