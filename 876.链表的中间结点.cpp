/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode *middleNode(ListNode *head)
    {
        bool flag = true;
        ListNode *p, *q;
        p = head;
        q = head;

        while (p != nullptr)
        {
            p = p->next;
            flag = !flag;
            if (flag)
            {
                q = q->next;
            }
        }
        return q;
    }
};

// √ Accepted
//   √ 15/15 cases passed (4 ms)
//   √ Your runtime beats 81.09 % of cpp submissions
//   √ Your memory usage beats 92.43 % of cpp submissions (8.3 MB)