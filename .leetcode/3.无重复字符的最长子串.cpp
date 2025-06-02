/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;
        int left = 0;
        int right = 0;

        int max_len = 0;
        int current_len = 0;
        while (right < s.size())
        {
            set.insert(s[right++]);
            current_len++;
            max_len = max(current_len, max_len);
            while (set.count(s[right]) > 0)
            {
                set.erase(s[left++]);
                --current_len;
            }
        }
        return max_len;
    }
};
// @lc code=end
