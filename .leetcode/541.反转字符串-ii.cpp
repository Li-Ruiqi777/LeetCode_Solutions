/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            if (s.size() - i < k)
                std::reverse(i + s.begin(), s.end());
            else
                std::reverse(i + s.begin(), i + k + s.begin());
        }
        return s;
    }
};
// @lc code=end
