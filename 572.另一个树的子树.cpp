/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr && t == nullptr)
        {
            return true;
        }
        else if (s != nullptr && t != nullptr)
        {
            if (s->val == t->val)
            {
                return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
            }
            else
                return false;
        }
        else
        {
            return false;
        }
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr)
        {
            return false;
        }
        if (isSameTree(t, s))
        {
            return true;
        }
        else
        {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};

// √ Accepted
//   √ 176/176 cases passed (64 ms)
//   √ Your runtime beats 44.02 % of cpp submissions
//   √ Your memory usage beats 78.32 % of cpp submissions (21 MB)