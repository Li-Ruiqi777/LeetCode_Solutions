/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 * 一刷:2024-10-2:没想出来异位词的str排序后是相同的
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
        unordered_map<string, vector<string>> map;
        for (auto &&str : strs)
        {
            string key = str;
            std::sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto && i:map){
            ans.emplace_back(i.second);
        }
        return ans;

    }
};
// @lc code=end
