/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 * 2024-10-15:一刷,没想出来,看了题解之后才写出来
 */

#include <queue>

// @lc code=start
class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        for (int i = 0; i < que.size() - 1; ++i)
        {
            que.push(que.front());
            que.pop();
        }
        auto ret = que.front();
        que.pop();
        return ret;
    }

    int top()
    {
        for (int i = 0; i < que.size() - 1; ++i)
        {
            que.push(que.front());
            que.pop();
        }
        auto ret = que.front();
        que.push(que.front());
        que.pop();
        return ret;
    }

    bool empty()
    {
        return que.empty();
    }

    std::queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
