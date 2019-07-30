/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
class Solution
{
public: //mid
    void create_leaves(TreeNode *root, vector<int> &vec)
    {
        if (root == nullptr)
        {
            return;
        }
        create_leaves(root->left, vec);
        if (root->left == nullptr && root->right == nullptr)
        {
            vec.push_back(root->val);
        }
        create_leaves(root->right, vec);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> left, right;
        create_leaves(root1, left);
        create_leaves(root2, right);
        if (left == right)
        {
            return true;
        }
        else
            return false;
    }
};

// √ Accepted
//   √ 36/36 cases passed (8 ms)
//   √ Your runtime beats 76.28 % of cpp submissions
//   √ Your memory usage beats 75.54 % of cpp submissions (14 MB)