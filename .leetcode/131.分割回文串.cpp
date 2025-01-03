/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 * 一刷:2025-1-3,每层for循环就是一个分割线，单个分割线切1个还是多个元素由它在for循环的索引决定
 * 结束条件：切割线的位置到达字符串末尾
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
private:
    vector<string> path;
    vector<vector<string>> res;

    bool isHuiwen(string &s)
    {
        if (s.size() == 1)
            return true;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }

    void backtrack(const string &s, int startIndex)
    {
        if (startIndex >= s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); ++i)
        {
            string sub = s.substr(startIndex, i - startIndex + 1);
            if (isHuiwen(sub))
                path.push_back(sub);
            else
                continue;

            backtrack(s, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtrack(s,0);
        return res;
    }
};
// @lc code=end
