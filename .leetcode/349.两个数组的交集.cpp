/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> sets;
        for (auto &&i : nums1)
        {
            sets.insert(i);
        }
        unordered_set<int> sets1;
        for (auto &&i : nums2)
        {
            if (sets.find(i) != sets.end())
            {
                sets1.insert(i);
            }
        }
        vector<int> result;
        for (auto &&i : sets1)
        {
            result.emplace_back(i);
        }
        return result;
    }
};
// @lc code=end
