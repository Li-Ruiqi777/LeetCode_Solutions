/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    static bool cmp(vector<int> &left, vector<int> &right)
    {
        if (left[0] == right[0])
            return left[1] < right[1];
        return left[0] < right[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), cmp);
        int remove_num = 0;
        for (int i = 0; i < intervals.size() - 1; ++i)
        {
            if(intervals[i+1][0] < intervals[i][1])
            {
                remove_num++;
                intervals[i+1][1] = min(intervals[i][1],intervals[i+1][1]);
            }
        }
        return remove_num;
    }
};
// @lc code=end
