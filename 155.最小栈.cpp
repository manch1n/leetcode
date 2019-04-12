/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (48.35%)
 * Total Accepted:    22.2K
 * Total Submissions: 45.8K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */
#include <vector>
using namespace std;
class MinStack
{
public:
    /** initialize your data structure here. */
    vector<int> vec;
    int min_index = 0;
    MinStack() : vec{/*!100 */}
    { //我把这里的构造函数想初始化为100个容量，没想到直接弄了个值为100的元素下去 汗！
    }

    void push(int x)
    {
        vec.push_back(x);
        if (x < vec[min_index])
        {
            min_index = vec.size() - 1;
        }
    }

    void pop()
    {
        if (vec.size() == 0)
            return;
        if (vec.size() - 1 == min_index)
        {
            int min = vec[0];
            min_index = 0;
            int s = vec.size();
            for (int i = 0; i < s - 1; i++)
            {
                if (vec[i] < min)
                {
                    min = vec[i];
                    min_index = i;
                }
            }
        }
        vec.pop_back();
    }

    int top()
    {
        if (vec.size() == 0)
            return -1;
        return vec[vec.size() - 1];
    }

    int getMin()
    {
        if (vec.size() == 0)
            return -1;
        return vec[min_index];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// √ Accepted
//   √ 18/18 cases passed (72 ms)
//   √ Your runtime beats 49.77 % of cpp submissions
//   √ Your memory usage beats 76.34 % of cpp submissions (16.8 MB)