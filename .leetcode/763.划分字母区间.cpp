/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> res;

        std::unordered_map<char, int> map;
        for (int i = 0; i < s.size(); ++i)
        {
            map[s[i]] = i;
        }
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            right = max(right,map[s[i]]);
            if(i == right)
            {
                res.push_back(i - left + 1);
                left = right + 1;
            }       
        }
        return res;
    }
};
// @lc code=end
