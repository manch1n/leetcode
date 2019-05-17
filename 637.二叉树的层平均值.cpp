/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */
/**
 * Definition for a binary tree node.*/
#include <vector>
#include <algorithm>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<TreeNode *> current;
        vector<TreeNode *> next;
        vector<double> result;
        current.push_back(root);
        while (current.size() != 0)
        {
            double sum = 0;
            for (auto n : current)
            {
                sum += n->val;
                if (n->left != nullptr)
                {
                    next.push_back(n->left);
                }
                if (n->right != nullptr)
                {
                    next.push_back(n->right);
                }
            }
            result.push_back(sum / current.size());
            current.swap(next);
            next.clear();
        }
        return result;
    }
};

// √ Accepted
//   √ 65/65 cases passed (28 ms)
//   √ Your runtime beats 96.9 % of cpp submissions
//   √ Your memory usage beats 89.71 % of cpp submissions (21.6 MB)