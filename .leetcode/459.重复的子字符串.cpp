/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 * 一刷:2024-10-10:没写出来
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end()-1);
        if(t.find(s)==std::string::npos)
            return false;
        return true;
    }
};
// @lc code=end

