/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (37.96%)
 * Total Accepted:    14.6K
 * Total Submissions: 38.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
 * 
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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        if (root->left == nullptr)
        {
            return 1 + minDepth(root->right);
        }
        else if (root->right == nullptr)
        {
            return 1 + minDepth(root->left);
        }
        else
        {
            int left_h = 1 + minDepth(root->left);
            int right_h = 1 + minDepth(root->right);
            return left_h > right_h ? right_h : left_h;
        }
    }
};

// √ Accepted
//   √ 41/41 cases passed (40 ms)
//   √ Your runtime beats 42.17 % of cpp submissions
//   √ Your memory usage beats 0.75 % of cpp submissions (19.5 MB)