/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 * 一刷:2024-9-21:没写出来,C++中map的count是key出现的次数，我把这个和value搞混了...
 */

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {

        if (t.size() > s.size())
            return "";
        if (t == s)
            return s;

        int length = INT_MAX;
        string ret = "";

        unordered_map<char, int> t_map, s_map;
        for (auto &&i : t)
            t_map[i]++;

        int left = 0;
        int right = 0;

        for (right = 0; right < s.size(); ++right)
        {
            ++s_map[s[right]];
            while (left <= right)
            {
                bool isOk = true;

                for (auto &&i : t_map)
                {
                    if (s_map[i.first] < i.second)
                    {
                        isOk = false;
                        break;
                    }
                }

                if (isOk)
                {
                    if (length > right - left + 1)
                    {
                        length = right - left + 1;
                        ret = s.substr(left, length);
                    }
                    --s_map[s[left]];
                    if (s_map[s[left]] == 0)
                        s_map.erase(s[left]);
                    ++left;
                }
                else
                    break;
            }
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    string ss = "bbaa";
    string t = "aba";
    Solution s;
    s.minWindow(ss, t);
    return 0;
}
