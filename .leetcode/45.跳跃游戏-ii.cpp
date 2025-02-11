/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>
#include <math.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0;
        int nextDistance = 0;
        int ans = 0;
        for(int i=0;i<nums.size();++i)
        {
            nextDistance = max(nums[i],nextDistance);
            if(i==curDistance){
                ans++;
                curDistance = nextDistance;
                if(curDistance >= nums.size()-1)
                    break;
            }
        }
        return ans;
    }
};
// @lc code=end

