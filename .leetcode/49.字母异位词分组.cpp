/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 * 一刷:2024-10-2:没想出来异位词的str排序后是相同的
 * 二刷:2025-4-14
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for (auto str : strs)
        {
            string key = str;
            std::sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        for(auto i:map)
        {
            result.push_back(i.second);
        }
        return result;
    }
};
// @lc code=end
