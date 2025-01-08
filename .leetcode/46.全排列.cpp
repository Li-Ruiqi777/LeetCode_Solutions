/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
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
    unordered_set<int> used;
    void backtrack(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
            

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!path.empty() && used.find(nums[i]) != used.end())
            {
                continue;
            }
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            used.erase(nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        res.clear();
        path.clear();
        backtrack(nums);
        return res;
    }
};
// @lc code=end
