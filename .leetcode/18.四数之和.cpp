/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 * 一刷:2024-10-6，看了题解，四数之和和三数之和基本一样，就多了个for循环，里面其实还是三数之和
 * 二刷:2024-10-14,基本上写出来了,但是忘记加long,剪枝、去重处理写的不对
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (int k = 0; k < nums.size(); ++k)
        {
            if (nums[k] >= 0 && nums[k] > target)
                break;
            if (k > 0 && nums[k] == nums[k - 1])
                continue;

            for (int i = k + 1; i < nums.size(); i++)
            {
                if (nums[k] + nums[i] >= 0 && nums[k] + nums[i] > target)
                    break;
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;

                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                        ++left;
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                        --right;

                    else
                    {
                        result.push_back({nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        while (left < right && nums[right] == nums[right - 1])
                            --right;

                        ++left;
                        --right;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
