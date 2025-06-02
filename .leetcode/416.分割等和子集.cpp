/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += i;
        }
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums)
        {
            for (int i = target; i >= num; i--)
            {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};
// @lc code=end
