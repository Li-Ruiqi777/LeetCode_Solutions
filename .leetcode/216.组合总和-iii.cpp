/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 * 2025-1-2:一刷
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    vector<int> path;
    vector<vector<int>> res;

public:
    void backtrack(int k, int n, int startIndex)
    {
        if (path.size() == k)
        {
            int sum = 0;
            for (int i : path)
            {
                sum += i;
            }
            if (sum == n)
                this->res.push_back(this->path);
        }

        for (int i = startIndex; i <= 9; ++i)
        {
            this->path.push_back(i);
            this->backtrack(k, n, i + 1);
            this->path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        path.clear();
        backtrack(k, n, 1);
        return this->res;
    }
};
// @lc code=end
