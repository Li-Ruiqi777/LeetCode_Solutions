/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 * 一刷：2025-1-3
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int> &candidates, int startIndex, int target)
    {
        int sum = 0;
        for (auto i : path)
        {
            sum += i;
        }
        if (sum >= target)
        {
            if (sum == target)
                res.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i)
        {
            path.push_back(candidates[i]);
            backtrack(candidates,i,target);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtrack(candidates,0,target);
        return res;
    }
};
// @lc code=end
