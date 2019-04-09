/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (62.12%)
 * Total Accepted:    16.1K
 * Total Submissions: 25.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
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

#include <vector>
using namespace std;

//减治法

class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() <= 0)
            return nullptr;
        TreeNode *root = new TreeNode{nums[nums.size() / 2]};
        vector<int> vec_left{nums.begin(), nums.begin() + nums.size() / 2};
        vector<int> vec_right{nums.begin() + nums.size() / 2 + 1, nums.end()};
        root->left = sortedArrayToBST(vec_left);
        root->right = sortedArrayToBST(vec_right);
        return root;
    }
};

// √ Accepted
//   √ 32/32 cases passed (48 ms)
//   √ Your runtime beats 56.56 % of cpp submissions
//   √ Your memory usage beats 0.89 % of cpp submissions (24.4 MB)