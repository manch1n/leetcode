/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int sumTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
            return sumTree(root->left) + sumTree(root->right) + root->val;
    }
    int sum = 0;
    void find(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        int left = sumTree(root->left);
        int right = sumTree(root->right);
        sum += left > right ? (left - right) : (right - left);
        find(root->left);
        find(root->right);
    }
    int findTilt(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        find(root);
        return sum;
    }
};

// √ Accepted
//   √ 75/75 cases passed (52 ms)
//   √ Your runtime beats 54.31 % of cpp submissions
//   √ Your memory usage beats 86.17 % of cpp submissions (21.7 MB)