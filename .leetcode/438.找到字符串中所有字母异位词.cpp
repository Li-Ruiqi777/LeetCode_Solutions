/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        std::unordered_map<char, int> needs;

        for (char i : p)
            needs[i]++;
        int left = 0;
        int right = 0;

        while (right < s.size())
        {
            while (right - left + 1 < p.size())
            {
                ++right;
                continue;
            }

            std::unordered_map<char, int> window;
            for (int i = left; i <= right; ++i)
                window[s[i]]++;

            bool flag = true;
            for (auto i : needs)
            {
                if (window[i.first] != i.second)
                    flag = false;
            }
            if (flag)
                res.push_back(left);
            left++;
            right++;
        }
        return res;
    }
};
// @lc code=end

   