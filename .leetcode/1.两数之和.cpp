/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 * 一刷:2024-10-2
 * 二刷:2025-4-14
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
            map.insert({nums[i], i});

        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = map.find(target - nums[i]);
            if (it != map.end() && i != (*it).second)
            {
                result.push_back(i);
                result.push_back((*it).second);
                break;
            }
        }
        return result;
    }
};
// @lc code=end
