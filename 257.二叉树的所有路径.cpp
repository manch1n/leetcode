/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (57.60%)
 * Total Accepted:    8K
 * Total Submissions: 13.8K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    void binaryTreePaths(TreeNode *root, vector<string> &vec, string str)
    {
        if (root == nullptr)
        {
            return;
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            str += "->";
            str += to_string(root->val);
            binaryTreePaths(root->right, vec, str);
        }
        else if (root->left != nullptr && root->right == nullptr)
        {
            str += "->";
            str += to_string(root->val);
            binaryTreePaths(root->left, vec, str);
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            str += "->";
            str += to_string(root->val);
            vec.push_back(str);
        }
        else
        {
            str += "->";
            str += to_string(root->val);
            binaryTreePaths(root->left, vec, str);
            binaryTreePaths(root->right, vec, str);
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> vecs;
        string str;
        if (root)
        {
            str += to_string(root->val);
        }
        else
            return vecs;
        if (root->left || root->right)
        {
            binaryTreePaths(root->left, vecs, str);
            binaryTreePaths(root->right, vecs, str);
        }
        else
        {
            vecs.push_back(str);
        } //上界

        return vecs;
    }
};
// √ Accepted
//   √ 209/209 cases passed (12 ms)
//   √ Your runtime beats 94.47 % of cpp submissions
//   √ Your memory usage beats 75.57 % of cpp submissions (12 MB)