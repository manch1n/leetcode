/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 *
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (58.94%)
 * Total Accepted:    9.7K
 * Total Submissions: 16.5K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用栈实现队列的下列操作：
 * 
 * 
 * push(x) -- 将一个元素放入队列的尾部。
 * pop() -- 从队列首部移除元素。
 * peek() -- 返回队列首部的元素。
 * empty() -- 返回队列是否为空。
 * 
 * 
 * 示例:
 * 
 * MyQueue queue = new MyQueue();
 * 
 * queue.push(1);
 * queue.push(2);  
 * queue.peek();  // 返回 1
 * queue.pop();   // 返回 1
 * queue.empty(); // 返回 false
 * 
 * 说明:
 * 
 * 
 * 你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty
 * 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
 * 
 * 
 */
#include <stack>
#include <vector>
using namespace std;
class MyQueue
{
public:
    stack<int> s;
    /** Initialize your data structure here. */
    MyQueue() : s{}
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        int size = s.size();
        vector<int> vec;
        for (int i = 0; i < size; i++)
        {
            vec.push_back(this->pop());
        }
        s.push(x);
        for (int i = size - 1; i >= 0; --i)
        {
            s.push(vec[i]);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (s.empty())
            return -1;
        int tmp = s.top();
        s.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek()
    {
        if (s.empty())
            return -1;
        return s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// √ Accepted
//   √ 17/17 cases passed (12 ms)
//   √ Your runtime beats 40.18 % of cpp submissions
//   √ Your memory usage beats 92.57 % of cpp submissions (8.6 MB)