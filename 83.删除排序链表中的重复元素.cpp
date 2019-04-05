/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (44.81%)
 * Total Accepted:    21.8K
 * Total Submissions: 48.7K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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

class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        ListNode *h = head;
        ListNode *p = head, *q = head->next;
        while ((p != nullptr) && (p->next != nullptr))
        {
            if (q->val == p->val)
            {
                if (q->next != nullptr)
                {
                    p->next = q->next;
                    q->next = nullptr;
                    delete q;
                    q = p->next;
                }
                else
                {
                    delete q;
                    p->next = nullptr;
                }
            }
            else
            {
                p = p->next;
                q = p->next;
            }
        }
        return h;
    }
};


// √ Accepted
//   √ 165/165 cases passed (20 ms)
//   √ Your runtime beats 11.39 % of cpp submissions
//   √ Your memory usage beats 0.99 % of cpp submissions (9.1 MB)
