/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */
/*
// Definition for a Node.*/
#include <vector>
using namespace std;
// class Node
// {
// public:
//     int val;
//     vector<Node *> children;

//     Node() {}

//     Node(int _val, vector<Node *> _children)
//     {
//         val = _val;
//         children = _children;
//     }
// };

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->children.size() == 0)
        {
            return 1;
        }
        else
        {
            int max = 0;
            for (auto n : root->children)
            {
                int tmp = 1 + maxDepth(n);
                if (tmp > max)
                {
                    max = tmp;
                }
            }
            return max;
        }
    }
};

// √ Accepted
//   √ 36/36 cases passed (220 ms)
//   √ Your runtime beats 87.27 % of cpp submissions
//   √ Your memory usage beats 36.21 % of cpp submissions (32.2 MB)