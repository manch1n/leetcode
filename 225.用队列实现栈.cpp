/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (57.33%)
 * Total Accepted:    8.8K
 * Total Submissions: 15.3K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用队列实现栈的下列操作：
 * 
 * 
 * push(x) -- 元素 x 入栈
 * pop() -- 移除栈顶元素
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 * 
 * 
 * 注意:
 * 
 * 
 * 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty
 * 这些操作是合法的。
 * 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
 * 
 * 
 */

#include <queue>
using namespace std;
class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() : q{}
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if (q.size() == 0)
            return -1;
        int tmp = q.front();
        q.pop();
        return tmp;
    }

    /** Get the top element. */
    int top()
    {
        if (q.size() == 0)
            return -1;
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// √ Accepted
//   √ 16/16 cases passed (8 ms)
//   √ Your runtime beats 95.29 % of cpp submissions
//   √ Your memory usage beats 75.78 % of cpp submissions (8.8 MB)