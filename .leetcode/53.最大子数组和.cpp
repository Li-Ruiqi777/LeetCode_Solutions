/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <vector>
#include <math.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int current_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};
// @lc code=end
