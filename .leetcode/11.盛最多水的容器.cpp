/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int result = 0;
        int slow = 0;
        int fast = height.size() - 1;
        while (fast != slow)
        {
            int t = min(height[fast], height[slow]) * (fast - slow);
            result = max(t, result);

            if(height[fast] > height[slow])
                slow++;
            else
                fast--;
        }
        return result;
    }
};
// @lc code=end
