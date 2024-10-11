/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 * 一刷:2024-10-11:忘记了双指针写这题的思路了
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        int fast = 0;
        for (fast = 0; fast < nums.size(); ++fast)
        {
            if (nums[fast] == val)
                continue;
            nums[slow++] = nums[fast];
        }
        return slow;
    }
};
// @lc code=end
