/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.85%)
 * Total Accepted:    27.5K
 * Total Submissions: 60K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 * 
 */
/**
 * Definition for a binary tree node.
 */
#include <vector>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
  public:
    bool isSymmetric(TreeNode *root)
    {
        /*! recurisive way */
        // if (root == nullptr)
        //     return true;
        // else
        //     return isSymmetric(root->left, root->right);

        /*! nonrecurisive way */
        vector<TreeNode *> v1;
        vector<TreeNode *> v2;
        if (root == nullptr)
            return true;
        v1.push_back(root->left);
        v1.push_back(root->right);
        int s = v1.size();
        bool has_node = false;
        //[0,i],(i,size)

        while (1)
        {
            for (int i = v1.size() / 2 - 1; i >= 0; i--)
            {
                if (v1[i] != nullptr && v1[s - 1 - i] != nullptr)
                {
                    if (v1[i]->val != v1[s - 1 - i]->val)
                    {
                        return false;
                    }
                    has_node |= true;
                }
                else if (v1[i] == nullptr && v1[s - 1 - i] == nullptr)
                {
                    continue;
                    has_node |= false;
                }
                else
                {
                    return false;
                }
            }
            for (int i = 0; i < s; i++)
            {
                v2.push_back(v1[i]->left);
                v2.push_back(v1[i]->right);
            }
            std::swap(v1, v2);
            v2.clear();
            if (!has_node)
            {
                return true;
            }
        }
    }

    // bool isSymmetric(TreeNode *l, TreeNode *r)
    // {
    //     if (l != nullptr && r != nullptr)
    //     {
    //         if (l->val != r->val)
    //         {
    //             return false;
    //         }
    //         return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    //     }
    //     else if (l == nullptr && r == nullptr)
    //     {
    //         return true;
    //     }
    //     else
    //         return false;
    // }
};
// √ Accepted
//   √ 193/193 cases passed (24 ms)
//   √ Your runtime beats 4.29 % of cpp submissions
//   √ Your memory usage beats 0.95 % of cpp submissions (14.6 MB)