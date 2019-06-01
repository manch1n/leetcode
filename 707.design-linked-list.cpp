/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] Design Linked List
 */
//emmm数据结构做过，我直接用list双向链表偷懒好了
#include <list>
class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    std::list<int> l;
    MyLinkedList()
    {
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= l.size())
        {
            return -1;
        }
        else
        {
            auto it = l.begin();
            for (int i = 0; i < index; ++i)
            {
                it++;
            }
            return *it;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        l.push_front(val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        l.push_back(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > l.size() || index < 0)
        {
            return;
        }
        auto it = l.begin();
        for (int i = 0; i < index; ++i)
        {
            it++;
        }
        l.insert(it, val);
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= l.size() || index < 0)
        {
            return;
        }
        auto it = l.begin();
        for (int i = 0; i < index; ++i)
        {
            it++;
        }
        l.erase(it);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

//这个样例好像错了
// × Wrong Answer
//   × 60/61 cases passed (N/A)
//   × testcase: '["MyLinkedList","addAtIndex","get","deleteAtIndex"]\n[[],[-1,0],[0],[-1]]'
//   × answer: [null,null,-1,null]
//   × expected_answer: [null,null,0,null]
//   × stdout: