/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int ss[26];
        for (auto &&i : s)
        {
            ss[i - 'a']++;
        }
        for (auto &&i : t)
        {
            ss[i - 'a']--;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (ss[i] != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.isAnagram("anagram","nagaram");
}