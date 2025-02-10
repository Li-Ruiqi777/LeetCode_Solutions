/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int count = 0;
        for(auto i : nums){
            count += i;
            
            if(count > result){
                result = count;
            }

            if (count < 0)
            {
                count = 0;
            }
            
            
        }
        return result;
    }
};
// @lc code=end

