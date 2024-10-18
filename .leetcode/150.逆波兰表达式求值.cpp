/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 * 一刷:2024-10-18:差一点写出来,想复杂了,只用一个栈就行了，用2个就会有问题.
 * 标准库中把字符串转为int: std::stoi()
 */
#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        std::stack<int> stk;

        int res = 0;
        if(tokens.size()==1)
            return std::stoi(tokens[0]);

        for (string token : tokens)
        {
            if (token == "+" ||
                token == "-" ||
                token == "*" ||
                token == "/")
            {
                int temp = 0;
                int s1, s2;
                s2 = stk.top();
                stk.pop();
                s1 = stk.top();
                stk.pop();

                if (token == "+")
                {
                    temp = s1 + s2;
                }
                else if (token == "-")
                {
                    temp = s1 - s2;
                }
                else if (token == "*")
                {
                    temp = s1 * s2;
                }
                else if (token == "/")
                {
                    temp = (s1 / s2);
                }
                stk.push(temp);
            }

            else
            {
                stk.push(std::stoi(token));
            }
        }
        return stk.top();
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<string> input = {"3","11","+","5","-"};
    s.evalRPN(input);
}