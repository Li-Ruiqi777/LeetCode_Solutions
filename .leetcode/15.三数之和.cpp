/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 * 一刷:2024-10-6:没思路，看了题解
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>0)
                break;

            if(i>0 && nums[i]==nums[i-1])
                continue;

            int left = i+1;
            int right = nums.size()-1;
            while(left<right)
            {
                if(nums[i] + nums[left] + nums[right]>0)
                    --right;
                else if(nums[i] + nums[left] + nums[right]<0)
                    ++left;
                
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left<right && nums[right]==nums[right-1]) --right;
                    while(left<right && nums[left]==nums[left+1]) ++left;

                    --right;
                    ++left;
                }
                
            }

        }

        return result;
    }
};
// @lc code=end

