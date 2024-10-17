/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 * 一刷:2024-10-17
 */
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        std::stack<char> left;
        for (auto i : s)
        {
            if (i == '(' ||
                i == '{' ||
                i == '[')
            {
                left.push(i);
            }
            else
            {
                if (left.empty())
                    return false;

                auto k = left.top();
                left.pop();
                switch (i)
                {
                case ')':
                    if (k != '(')
                        return false;
                    break;
                case ']':
                    if (k != '[')
                        return false;
                    break;
                case '}':
                    if (k != '{')
                        return false;
                    break;

                default:
                    return false;
                    break;
                }
            }
        }
        if(!left.empty())
            return false;
        return true;
    }
};
// @lc code=end
