/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(const vector<int> &nums, int startIndex)
    {
        if (path.size() == nums.size())
        {
            return;
        }

        for (int i = startIndex; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            res.push_back(path);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums,0);
        res.push_back(vector<int>());
        return res;
    }
};
// @lc code=end
