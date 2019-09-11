/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 */
/**
 * Definition for a binary tree node.*/
//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
//  };

class Solution
{
public:
    int sum = 0;
    inline int turn(int num, int base)
    {
        int tbase = 1;
        int result = 0;
        while (base)
        {
            if (num & base)
            {
                result += tbase;
            }
            base /= 2;
            tbase *= 2;
        }
        return result;
    }
    void fst(TreeNode *root, int presum, int basesum)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            sum += turn(presum + root->val * basesum, basesum);
            return;
        }
        fst(root->left, presum + root->val * basesum, basesum * 2);
        fst(root->right, presum + root->val * basesum, basesum * 2);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        fst(root, 0, 1);
        return sum;
    }
};

// √ Accepted
//   √ 63/63 cases passed (8 ms)
//   √ Your runtime beats 86.76 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (17 MB)