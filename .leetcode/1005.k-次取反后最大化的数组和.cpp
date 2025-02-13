/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (k == 0)
                break;
            if (nums[i] < 0)
            {
                nums[i] = -nums[i];
                --k;
            }
        }

        std::sort(nums.begin(), nums.end());
        while(k>0)
        {
            nums[0] = -nums[0];
            --k;
        }
        int sum = 0;
        for(int i=0;i<nums.size();++i)
            sum += nums[i];

        return sum;
    }
};
// @lc code=end
