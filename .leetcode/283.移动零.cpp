/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 * 一刷:2024-9-18
 * 二刷:2025-4-15：看了题解...
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i] != 0)
            {
                nums[slow] = nums[i];
                slow++;
            }
        }
        for(int i=slow;i<nums.size();++i)
        {
            nums[i] = 0;
        }
 
    }
};
// @lc code=end
