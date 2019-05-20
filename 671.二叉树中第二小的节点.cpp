/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 */
/**
 * Definition for a binary tree node.*/
#include <queue>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

//优先队列中的出队 层序遍历一下即可
class Solution
{
public:
    int find(TreeNode *root, int min)
    {
        if (root == nullptr)
        {
            return -1;
        }
        if (root->val == min)
        {
            int left = find(root->left, min);
            int right = find(root->right, min);
            if (left == -1 || right == -1)
            {
                return left == -1 ? right : left;
            }
            else
                return left < right ? left : right;
        }
        else
        {
            return root->val;
        }
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        // queue<TreeNode *> q;
        // q.push(root);
        // int min = root->val;
        // while(q.empty()==false)
        // {
        //     auto n = q.front();
        //     q.pop();
        //     if(n->val!=min)
        //     {
        //         return n->val;
        //     }
        //     if(n->left!=nullptr)
        //     {
        //         q.push(n->left);
        //         q.push(n->right);
        //     }
        // }
        // return -1;
        return find(root, root->val);
    }
};

// √ Accepted
//   √ 35/35 cases passed (0 ms)
//   √ Your runtime beats 100 % of cpp submissions
//   √ Your memory usage beats 57.34 % of cpp submissions (8.7 MB)