/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (59.58%)
 * Total Accepted:    12.7K
 * Total Submissions: 21.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.*/
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr)
            return vector<vector<int>>{};
        vector<vector<int>> vecs;

        vector<TreeNode *> current, next;
        current.push_back(root);
        while (current.size() != 0)
        {
            int i=0,s=current.size();
            vector<int> vec;

            while(i<s)
            {
                if(current[i]->left!=nullptr) 
                {
                    next.push_back(current[i]->left);
                }
                if(current[i]->right!=nullptr)
                {
                    next.push_back(current[i]->right);
                }

                vec.push_back(current[i]->val);
                i++;
            }
            vecs.push_back(vec);
            std::swap(current,next);
            next.clear();
        }
        reverse(vecs.begin(),vecs.end());   
        return vecs;
    }
};


// √ Accepted
//   √ 34/34 cases passed (24 ms)
//   √ Your runtime beats 58.62 % of cpp submissions
//   √ Your memory usage beats 0.89 % of cpp submissions (13.8 MB)