/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */
/**
 * Definition for a binary tree node.*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
#include <vector>

class Solution
{
public:
    std::vector<TreeNode *> vec;
    void bst(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        bst(root->left);
        vec.push_back(root);
        bst(root->right);
    }

    TreeNode *convertBST(TreeNode *root)
    {
        bst(root);
        int size = vec.size();
        for (int i = size - 2; i >= 0; --i)
        {
            vec[i]->val += vec[i + 1]->val;
        }
        return root;
    }
};

// √ Accepted
//   √ 212/212 cases passed (68 ms)
//   √ Your runtime beats 72.91 % of cpp submissions
//   √ Your memory usage beats 79.1 % of cpp submissions (24.3 MB)