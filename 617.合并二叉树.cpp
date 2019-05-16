/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr && t2 == nullptr)
        {
            return nullptr;
        }
        else if (t1 != nullptr && t2 != nullptr)
        {
            TreeNode *n = new TreeNode(t1->val + t2->val);
            n->left = mergeTrees(t1->left, t2->left);
            n->right = mergeTrees(t1->right, t2->right);
            return n;
        }
        else if (t1 != nullptr && t2 == nullptr)
        {
            TreeNode *n = new TreeNode(t1->val);
            n->left = mergeTrees(t1->left, nullptr);
            n->right = mergeTrees(t1->right, nullptr);
            return n;
        }
        else
        {
            TreeNode *n = new TreeNode(t2->val);
            n->left = mergeTrees(nullptr, t2->left);
            n->right = mergeTrees(nullptr, t2->right);
            return n;
        }
    }
};

// √ Accepted
//   √ 183/183 cases passed (88 ms)
//   √ Your runtime beats 44.08 % of cpp submissions
//   √ Your memory usage beats 7.04 % of cpp submissions (23.9 MB)
