/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 * 一刷:2024-9-18
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        int slowIdx = 0;
        int fastIdx = 1;
        for (int fastIdx = 0; fastIdx < nums.size(); fastIdx++)
        {
            if (nums[fastIdx] != 0)
            {
                auto temp = nums[slowIdx];
                nums[slowIdx] = nums[fastIdx];
                nums[fastIdx] = temp;
                ++slowIdx;
            }
        }
    }
};
// @lc code=end
