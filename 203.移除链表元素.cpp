/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (40.09%)
 * Total Accepted:    21.6K
 * Total Submissions: 53.4K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */
/**
 * Definition for singly-linked list.*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };


//一个=号引发的调试惨案
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *p = nullptr, *q = head;
        while (q != nullptr)
        {
            if (q->val ==/* = */ val)  //！！！！！
            {
                if (p != nullptr && q->next != nullptr)
                {
                    p->next = q->next;
                    delete q;
                    q = p->next;
                    continue;
                }
                else if (q->next == nullptr)
                {
                    if (p)
                    {
                        p->next = nullptr;
                    }
                    else
                    {
                        head = nullptr;
                    }
                    delete q;
                    q = nullptr;
                    continue;
                }
                else
                {
                    p = q;
                    q = q->next;
                    delete p;
                    p = nullptr;
                    head = q;
                    continue;
                }
            }
            p = q;
            q = q->next;
        }
        return head;
    }
};
// √ Accepted
//   √ 65/65 cases passed (48 ms)
//   √ Your runtime beats 62.13 % of cpp submissions
//   √ Your memory usage beats 84.42 % of cpp submissions (11 MB)