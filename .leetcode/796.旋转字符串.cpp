/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    void moveLeft2End(string &s)
    {
        std::reverse(s.begin(), s.end());
        std::reverse(s.begin(), s.end() - 1);
    }

    bool rotateString(string s, string goal)
    {
        for (int i = 0; i <= s.size(); ++i)
        {
            if (s == goal)
                return true;
            else
                moveLeft2End(s);
        }
        return false;
    }
};
// @lc code=end
