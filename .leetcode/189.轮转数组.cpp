/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        std::reverse(nums.begin(),nums.end());
        std::reverse(nums.begin(),nums.begin()+k);
        std::reverse(nums.begin()+k,nums.end());
    }
};
// @lc code=end
