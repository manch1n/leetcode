/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
/**
 * Definition for a binary tree node.*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

#include <limits>
class Solution
{
public:
    //二叉搜索树，直接中序遍历出大小结果即可。
    int min = std::numeric_limits<int>::max();
    int prev = std::numeric_limits<int>::max();
    int getMinimumDifference(TreeNode *root)
    {
        midfs(root);
        return min;
    }
    void midfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        midfs(root->left);
        int abs = std::abs(root->val - prev);
        if (abs < min)
        {
            min = abs;
        }
        prev = root->val;
        midfs(root->right);
    }
};

// √ Accepted
//   √ 186/186 cases passed (40 ms)
//   √ Your runtime beats 93.75 % of cpp submissions
//   √ Your memory usage beats 94.19 % of cpp submissions (21.7 MB)