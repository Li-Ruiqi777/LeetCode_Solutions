/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 * 一刷:2024-10-6:没思路，看了题解
 * 二刷:2024-10-14:还是没思路,又是看了题解才写出来的
 * 三刷:2025-4-15:超时了
 * 三数之和其实就是先固定一个数的两数之和或者固定2个数找另一个数
 * 前者时间复杂度更低
 */

#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    result.push_back(temp);
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right - 1] == nums[right])
                        right--;
                    left++;
                    right--;
                }
                else if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
            }
        }
        return result;
    }
};
// @lc code=end
