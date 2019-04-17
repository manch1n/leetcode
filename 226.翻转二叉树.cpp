/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 *
 * https://leetcode-cn.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (68.00%)
 * Total Accepted:    14.3K
 * Total Submissions: 20.9K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 翻转一棵二叉树。
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * 输出：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * 备注:
 * 这个问题是受到 Max Howell 的 原问题 启发的 ：
 * 
 * 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
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

#include <iostream>
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {

        //后序遍历
        if (!root)
            return root;
        if (root->left)
            invertTree(root->left);
        if (root->right)
            invertTree(root->right);

        //有一个存在就进行交换
        if (root->left || root->right)
        {
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return root;
    }
};
// √ Accepted
//   √ 68/68 cases passed (8 ms)
//   √ Your runtime beats 92.08 % of cpp submissions
//   √ Your memory usage beats 64.84 % of cpp submissions (9.1 MB)