/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26];
        for(auto &&c : magazine)
        {
            record[c-'a']++;
        }

        for(auto &&c : ransomNote)
        {
            record[c-'a']--;
        }

        for(auto i :record)
        {
            if(i<0)
                return false;
        }
        return true;
    }
};
// @lc code=end

