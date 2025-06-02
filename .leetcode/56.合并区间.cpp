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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        if (intervals.empty())
            return result;
  
        std::sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            auto& current_interval = result.back();
        
            if (current_interval[1] < intervals[i][0])
            {
                result.push_back(intervals[i]);   
            }
            else
            {
                current_interval[1] = max(current_interval[1], intervals[i][1]);
            }
                
        }
        return result;
    }
};
// @lc code=end
