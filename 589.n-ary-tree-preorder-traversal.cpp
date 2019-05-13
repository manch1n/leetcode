/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */
/*
// Definition for a Node.*/
#include <vector>
#include <stack>
using namespace std;
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

class Solution
{
public:
    //recursive
    // void pre(Node* root,vector<int>& vec)
    // {
    //     if(root==nullptr)
    //     {
    //         return;
    //     }
    //     vec.push_back(root->val);
    //     for(auto n:root->children)
    //     {
    //         pre(n,vec);
    //     }
    // }
    vector<int> preorder(Node *root)
    {
        //想不出迭代的
        //利用两个栈。
        if (root == nullptr)
        {
            return {};
        }
        stack<Node *> s;
        stack<Node *> tmp;
        s.push(root);
        vector<int> res;
        while (s.empty() == false)
        {
            auto n = s.top();
            s.pop();
            res.push_back(n->val);
            for (auto t : n->children)
            {
                tmp.push(t);
            }
            while (tmp.empty() == false)
            {
                s.push(tmp.top());
                tmp.pop();
            }
        }
        return res;
    }
};

// √ Accepted
//   √ 36/36 cases passed (364 ms)
//   √ Your runtime beats 33.83 % of cpp submissions
//   √ Your memory usage beats 93.58 % of cpp submissions (32.4 MB)

// √ Accepted
//   √ 36/36 cases passed (288 ms)
//   √ Your runtime beats 57.93 % of cpp submissions
//   √ Your memory usage beats 49.72 % of cpp submissions (33.1 MB)