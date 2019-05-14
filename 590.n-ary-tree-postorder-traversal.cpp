/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */
/*
// Definition for a Node.*/
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
//recursive way
    // void post(Node* root,vector<int> &vec)
    // {
    //     if(root==nullptr)
    //     {
    //         return;
    //     }
    //     for(auto n:root->children)
    //     {
    //         post(n, vec);
    //     }
    //     vec.push_back(root->val);
    // }
    vector<int> postorder(Node* root) {
        if(root==nullptr)
        {
            return {};
        }
        vector<int> result;
        while(root->children.size()!=0)
        {
            
        }
    }
};

// √ Accepted
//   √ 36/36 cases passed (392 ms)
//   √ Your runtime beats 23.89 % of cpp submissions
//   √ Your memory usage beats 78.13 % of cpp submissions (32.7 MB)