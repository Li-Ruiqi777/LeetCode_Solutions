/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
    vector<bool> used;
    void backtrack(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        unordered_set<int> used_num; //同层去重,而不是深度方向去重
        for (int i = 0; i < nums.size(); ++i)
        {
            if ((!path.empty() && used[i] == true) ||
                (used_num.find(nums[i]) != used_num.end()))
            {
                continue;
            }
            used[i] = true;
            used_num.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        res.clear();
        path.clear();
        this->used.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }
};
// @lc code=end
