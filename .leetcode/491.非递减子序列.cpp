/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, int startIndex)
    {
        if (path.size() > 1)
            res.push_back(path);

        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); ++i)
        {
            if ((!path.empty() && nums[i] < path.back()) ||
                uset.find(nums[i]) != uset.end())
            {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtrack(nums, 0);
        return res;
    }
};
// @lc code=end
