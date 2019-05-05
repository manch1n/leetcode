/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
using namespace std;
//先序：先遍历根再左右
//中序：先遍历左再中右
//后序：先遍历左再右根
class Solution
{
public:
    int num = 0;
    int count = 0;
    int maxcount = 0;
    vector<int> result;
    vector<int> findMode(TreeNode *root)
    {
        midst(root);
        return result;
    }

    void midst(TreeNode *root)
    {
        if (root == nullptr)
            return;
        midst(root->left);
        if (num == root->val)
        {
            count++;
        }
        else
        {
            count = 1;
        }

        if (count > maxcount)
        {
            result.clear();
            maxcount = count;
            result.push_back(root->val);
        }
        else if (count == maxcount)
        {
            result.push_back(root->val);
        }
        num = root->val;
        midst(root->right);
        return;
    }
};

// √ Accepted
//   √ 25/25 cases passed (60 ms)
//   √ Your runtime beats 42.91 % of cpp submissions
//   √ Your memory usage beats 81.51 % of cpp submissions (23.2 MB)