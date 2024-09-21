/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 * 一刷:2024-9-19：用快慢指针没写出来，这题用栈来写很简单，但是用快慢指针感觉还是有点难的
 */

#include <string>
#include <iostream>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        std::stack<char> stackS, stackT;
        for (auto c : s)
        {
            if (c == '#' && !stackS.empty())
                stackS.pop();
            else if(c != '#')
                stackS.push(c);
        }

        for (auto c : t)
        {
            if (c == '#' && !stackT.empty())
                stackT.pop();
            else if(c != '#')
                stackT.push(c);
        }

        if (stackS.size() != stackT.size())
            return false;

        while (!stackS.empty())
        {
            if (stackS.top() != stackT.top())
                return false;
            stackS.pop();
            stackT.pop();
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    string s1 = "y#fo##f";
    string s2 = "y#f#o##f";
    bool res = s.backspaceCompare(s1, s2);

    return 0;
}
