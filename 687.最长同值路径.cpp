/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 */
/**
 * Definition for a binary tree node.*/
#include <algorithm>
using namespace std;
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
    int current_max = 0;
    int longestUnivaluePath(TreeNode *root)
    {
        dfs(root);
        return current_max;
    }

    int dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (root->left != nullptr && root->val == root->left->val)
        {
            left += 1;
        }
        else
        {
            left = 0;
        }
        if (root->right != nullptr && root->val == root->right->val)
        {
            right += 1;
        }
        else
        {
            right = 0;
        }
        current_max = max(current_max, left + right);
        return max(left, right);
    }
};
// √ Accepted
//   √ 71/71 cases passed (176 ms)
//   √ Your runtime beats 97.27 % of cpp submissions
//   √ Your memory usage beats 55.88 % of cpp submissions (49.9 MB)