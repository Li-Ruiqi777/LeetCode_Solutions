/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 * 一刷:2025-1-3，这题的去重是要同一层横向（回溯）去重，而不是在某一个分支纵向（递归）去重，所以不只是candidates[i] == candidates[i - 1]，
 * 还要判断startIndex
 */

#include <vector>
#include <algorithm>
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
            // 同一层去重
            if (i > startIndex && candidates[i] == candidates[i - 1])
                continue;

            path.push_back(candidates[i]);
            backtrack(candidates, i + 1, target);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }
};
// @lc code=end
