/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */
/**
 * Definition for a binary tree node.*/

#include <string>
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
    void pre(TreeNode *root, string &s)
    {
        if (root == nullptr)
        {
            return;
        }
        s += '(';
        s += to_string(root->val);
        if (root->left == nullptr && root->right != nullptr)  //这一步有点折腾
        {
            s += "()";
        }
        pre(root->left, s);
        pre(root->right, s);
        s.push_back(')');
    }
    string tree2str(TreeNode *t)
    {
        if (t == nullptr)
        {
            return "";
        }
        string result;
        pre(t, result);
        result.erase(result.begin());
        result.erase(result.end() - 1);
        // while(1)
        // {
        //     size_t pos = result.find("()");
        //     if(pos==string::npos)
        //     {
        //         break;
        //     }
        //     result.erase(result.begin() + pos,result.begin()+pos+2);
        // }
        return result;
    }
};

// √ Accepted
//   √ 162/162 cases passed (40 ms)
//   √ Your runtime beats 92.09 % of cpp submissions
//   √ Your memory usage beats 96.93 % of cpp submissions (21.5 MB)