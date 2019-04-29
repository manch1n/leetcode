/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum2(TreeNode *root, int rest)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int diff = rest - root->val;
        if (diff == 0)
        {
            return 1 + pathSum2(root->left, diff) + pathSum2(root->right, diff);
        }
        else
        {
            return pathSum2(root->left, diff) + pathSum2(root->right, diff);
        }
    }
    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;
        int i = pathSum2(root, sum);
        int l = pathSum(root->left, sum);
        int r = pathSum(root->right, sum);
        return i + l + r;
    }
};

//真折腾
// √ Accepted
//   √ 126/126 cases passed (56 ms)
//   √ Your runtime beats 37.21 % of cpp submissions
//   √ Your memory usage beats 80.49 % of cpp submissions (14.6 MB)