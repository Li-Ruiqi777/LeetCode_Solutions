/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 * 一刷:2024-10-6:看了题解才会写的
 * 二刷:2024-10-11:秒了
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size()-1;
        while (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
    }
};
// @lc code=end
