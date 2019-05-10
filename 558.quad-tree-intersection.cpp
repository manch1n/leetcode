/*
 * @lc app=leetcode.cn id=558 lang=cpp
 *
 * [558] Quad Tree Intersection
 */
/*
// Definition for a QuadTree node.*/
// class Node
// {
// public:
//     bool val;
//     bool isLeaf;
//     Node *topLeft;
//     Node *topRight;
//     Node *bottomLeft;
//     Node *bottomRight;

//     Node() {}

//     Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
//     {
//         val = _val;
//         isLeaf = _isLeaf;
//         topLeft = _topLeft;
//         topRight = _topRight;
//         bottomLeft = _bottomLeft;
//         bottomRight = _bottomRight;
//     }
// };
//感觉这种四叉树的题纯碎来恶心人。。。
class Solution
{
public:
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        if (quadTree1->isLeaf && quadTree1->val)
            return quadTree1;
        if (quadTree2->isLeaf && quadTree2->val)
            return quadTree2;
        if (quadTree1->isLeaf && !quadTree1->val)
            return quadTree2;
        if (quadTree2->isLeaf && !quadTree2->val)
            return quadTree1;

        auto tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        auto tr = intersect(quadTree1->topRight, quadTree2->topRight);
        auto bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        auto br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (tl->val == tr->val && tl->val == bl->val && tl->val == br->val && tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf)
            return new Node(tl->val, true, nullptr, nullptr, nullptr, nullptr); //说明是叶子节点
        else
            return new Node(false, false, tl, tr, bl, br); //普通的四叉树节点
    }
};

// √ Accepted
//   √ 58/58 cases passed (692 ms)
//   √ Your runtime beats 48.15 % of cpp submissions
//   √ Your memory usage beats 61.76 % of cpp submissions (49.3 MB)