/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    static bool cmp(const vector<int> &left, const vector<int> &right)
    {
        if (left[0] == right[0])
            return left[1] < right[1];
        return left[0] < right[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), Solution::cmp);
        vector<vector<int>> res;

        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }

        }
        return res;
    }
};
// @lc code=end
