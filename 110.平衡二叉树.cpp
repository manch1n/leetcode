/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (47.05%)
 * Total Accepted:    13.8K
 * Total Submissions: 29.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
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
    int abs(int num)
    {
        if (num > 0)
            return num;
        else
            return -num;
    }

    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = 1 + height(root->left);
        int right = 1 + height(root->right);
        return left > right ? left : right;
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        int left_h = height(root->left);
        int right_h = height(root->right);
        if (abs(left_h - right_h) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// √ Accepted
//   √ 227/227 cases passed (28 ms)
//   √ Your runtime beats 92.2 % of cpp submissions
//   √ Your memory usage beats 0.87 % of cpp submissions (16.4 MB)
