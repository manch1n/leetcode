/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val == val)
        {
            return root;
        }
        if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
    }
};

// √ Accepted
//   √ 36/36 cases passed (56 ms)
//   √ Your runtime beats 99.12 % of cpp submissions
//   √ Your memory usage beats 72.84 % of cpp submissions (29.1 MB)
