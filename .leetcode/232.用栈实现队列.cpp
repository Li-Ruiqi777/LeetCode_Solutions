/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 * 一刷:2024-10-15:一刷,虽然AC了但是时间复杂度很高,写得没标准答案好,我的2个栈没有都充分用到
 */

#include <stack>

// @lc code=start
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s_main.push(x);
    }

    int pop()
    {
        while (!s_main.empty())
        {
            auto i = s_main.top();
            s_main.pop();
            s_sub.push(i);
        }
        int ret = s_sub.top();
        s_sub.pop();

        while (!s_sub.empty())
        {
            auto i = s_sub.top();
            s_sub.pop();
            s_main.push(i);
        }
        return ret;
    }

    int peek()
    {
        while (!s_main.empty())
        {
            auto i = s_main.top();
            s_main.pop();
            s_sub.push(i);
        }
        auto i = s_sub.top();
        while (!s_sub.empty())
        {
            auto i = s_sub.top();
            s_sub.pop();
            s_main.push(i);
        }
        return i;
    }

    bool empty()
    {
        return s_main.empty();
    }

private:
    std::stack<int> s_main;
    std::stack<int> s_sub;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
