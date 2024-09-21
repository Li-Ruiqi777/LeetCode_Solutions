/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 * 一刷：2024-9-20,这题看了题解才知道滑动窗口法,使用该方法时首先要确定3个东西:
 * 1.窗口内是什么？
 * 2.如何移动窗口的起始位置？
 * 3.如何移动窗口的结束位置？
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int isFind = -1;
        int left = 0;
        int sum = 0;
        int min_length = __INT32_MAX__;
        for (int right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            while (sum >= target)
            {
                sum -= nums[left];
                isFind = 1;
                if (right - left + 1 < min_length)
                    min_length = right - left + 1;
                ++left;
            }
        }
        return isFind == -1 ? 0 : min_length;
    }
};
// @lc code=end
