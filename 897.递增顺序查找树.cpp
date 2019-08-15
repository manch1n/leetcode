/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
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
    TreeNode *head, *tail;
    bool first = true;
    void bst(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        bst(root->left);
        auto p = new TreeNode(root->val);
        if (first)
        {
            first = false;
            head = p;
            tail = p;
        }
        else
        {
            tail->right = p;
            tail = p;
        }
        bst(root->right);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        bst(root);
        return head;
    }
};
// √ Accepted
//   √ 2156/2156 cases passed (68 ms)
//   √ Your runtime beats 38.29 % of cpp submissions
//   √ Your memory usage beats 75.61 % of cpp submissions (25 MB)