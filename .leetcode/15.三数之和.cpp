/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 * 一刷:2024-10-6:没思路，看了题解
 * 二刷:2024-10-14:还是没思路,又是看了题解才写出来的
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                return result;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] < 0)
                    ++left;
                else if (nums[i] + nums[left] + nums[right] > 0)
                    --right;
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) //这里去重和别的地方不一样
                        ++left;
                    while (right > left && nums[right] == nums[right - 1])
                        --right;

                    ++left;
                    --right;
                }
            }
        }

        return result;
    }
};
// @lc code=end
