/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <string>
using namespace std;
#include <vector>
// @lc code=start
class Solution
{
private:
    vector<string> path;
    vector<string> res;
    string fusePath(vector<string> &path)
    {
        string s;
        for (auto &i : path)
        {
            s.append(i);
            s.append(".");
        }
        s.pop_back();
        return s;
    }

    bool isNormal(string &input)
    {
        if (input.front() == '0' && input.size() > 1)
            return false;
        try
        {
            int num = stoi(input);
            if (num > 255)
                return false;
        }
        catch (const std::exception &e)
        {
            return false;
        }
        return true;
    }

    void backtrack(const string &s, int startIndex)
    {
        if (path.size() == 4)
        {
            string temp = fusePath(path);
            if (temp.size() == s.size() + 3)
                res.push_back(temp);
            return;
        }
        if (startIndex == s.size())
            return;

        for (int i = startIndex; i < s.size(); ++i)
        {
            //剪枝
            if (i - startIndex > 3)
                return;
            string sub = s.substr(startIndex, i - startIndex + 1);
            if (isNormal(sub))
                path.push_back(sub);
            else
                continue;
            backtrack(s, i + 1);
            path.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        backtrack(s, 0);
        return res;
    }
};
// @lc code=end
