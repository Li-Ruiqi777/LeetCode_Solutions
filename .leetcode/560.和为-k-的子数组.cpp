/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;
        std::unordered_map<int, int> prefix_sum;
        int sum = 0;
        prefix_sum[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (prefix_sum.count(sum - k) > 0)
                res += prefix_sum[sum - k];
            prefix_sum[sum]++;
        }

        return res;
    }
};
// @lc code=end
