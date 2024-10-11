/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 * 一刷:2024-10-7,这题如果不考虑空间复杂度还是很简单的,但是如果要O(1),还是有点难的对我来说.
 *  思路:先去掉所有空格,再去反转整个str,再反转每个单词
 * 二刷:2024-10-11,忘记怎么移除空格了
 */

#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    void removeEmpty(string &s)
    {
        int slow_idx = 0;
        int fast_idx = 0;

        // 移除头部空格
        while (fast_idx < s.size() && s[fast_idx] == ' ')
            ++fast_idx;

        // 移除中间的空格
        for (; fast_idx < s.size(); ++fast_idx)
        {
            if (fast_idx > 0 && s[fast_idx - 1] == s[fast_idx] && s[fast_idx] == ' ')
                continue;
            s[slow_idx++] = s[fast_idx];
        }

        // 移除末尾空格
        if (s[fast_idx - 1] == ' ')
            s.resize(slow_idx - 1);
        else
            s.resize(slow_idx);
    }

    void swapStr(string &s, int start, int end)
    {
        if (start < 0 || end >= s.size())
            return;

        int left = start;
        int right = end;

        while (left < right)
        {
            auto temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            --right;
            ++left;
        }
    }

    string reverseWords(string s)
    {
        this->removeEmpty(s);
        this->swapStr(s, 0, s.size() - 1);
        int left = 0;
        int right = 0;
        while (left < s.size())
        {
            for (right = left; right < s.size(); ++right)
            {
                if (s[right] == ' ')
                {
                    this->swapStr(s, left, right - 1);
                    left = right + 1;
                }
                    
                else if(right == s.size() - 1)
                {
                    this->swapStr(s, left, right);
                    left = right + 1;
                }  
            }
        }
        return s;
    }
};
// @lc code=end
