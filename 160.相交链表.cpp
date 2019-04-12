/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 *
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (40.10%)
 * Total Accepted:    21.8K
 * Total Submissions: 54.2K
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3'
 *
 * 编写一个程序，找到两个单链表相交的起始节点。
 * 
 * 如下面的两个链表：
 * 
 * 
 * 
 * 在节点 c1 开始相交。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2,
 * skipB = 3
 * 输出：Reference of the node with value = 8
 * 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为
 * [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB
 * = 1
 * 输出：Reference of the node with value = 2
 * 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为
 * [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * 输出：null
 * 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为
 * 0，而 skipA 和 skipB 可以是任意值。
 * 解释：这两个链表不相交，因此返回 null。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 如果两个链表没有交点，返回 null.
 * 在返回结果后，两个链表仍须保持原有的结构。
 * 可假定整个链表结构中没有循环。
 * 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 * 
 * 
 */
/**
 * Definition for singly-linked list.*/
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *p = headA, *q = headB;
        /*!get len */
        int lena = 0, lenb = 0;
        while (p)
        {
            ++lena;
            p = p->next;
        }
        while (q)
        {
            ++lenb;
            q = q->next;
        }
        /*!get len */
        p = headA;
        q = headB; //reset
        if (lena > lenb)
        {
            int dif = lena - lenb;
            while (dif--)
            {
                p = p->next;
            }
        }
        else
        {
            int dif = lenb - lena;
            while (dif--)
            {
                q = q->next;
            }
        }
        int val = p->val;
        bool find = false;
        while (p && q)
        {
            if (p->val == q->val)
            {
                if (find == false)
                {
                    find = true;
                    val = p->val;
                }
                else
                {
                }
            }
            else
            {
                find = false;
            }
            p = p->next;
            q = q->next;
        }
        if (find)
        {
            return new ListNode{val};
        }
        else
            return nullptr;
        //这道题哪里给了输入数字了QAQ，原来题意说是在结尾处2333
        // if(headA==nullptr||headB==nullptr) return nullptr;
        // int minb=headB->val;
        // int maxb=headB->val;
        // ListNode* p=headA,*q=headB;
        // while(q)
        // {
        //     if(q->val>maxb) maxb=q->val;
        //     if(q->val>minb) minb=q->val;
        //     q=q->next;
        // }
        // q=headB;   //reset
        // while(p)
        // {
        //     if(p->val>maxb&&p->val<minb)
        //     {
        //         p=p->next;
        //         continue;
        //     }
        //     while(q)
        //     {
        //         if(p->val==q->val)
        //         {
        //             ListNode* r=new ListNode{p->val};
        //             return r;
        //         }
        //         q=q->next;
        //     }
        //     p=p->next;
        // }
        // return nullptr;
    }
};

//这个特例答案应该是错了

// × Wrong Answer
//   × 44/45 cases passed (N/A)
//   × testcase: '8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3'
//   × answer: Intersected at '1'
//   × expected_answer: Intersected at '8'
//   × stdout:
