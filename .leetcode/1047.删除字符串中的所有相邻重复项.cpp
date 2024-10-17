/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 * 一刷:2024-10-17
 */

#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        std::stack<char> stk;
        for (auto i : s)
        {
            if (stk.empty())
            {
                stk.push(i);
                continue;
            }

            auto last = stk.top();
            if (i == last)
                stk.pop();
            else
                stk.push(i);
        }

        string ret;
        while(!stk.empty())
        {
            auto last = stk.top();
            ret.push_back(last);
            stk.pop();
        }

        std::reverse(ret.begin(),ret.end());
        return ret;
    }
};
// @lc code=end
