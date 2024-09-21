/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 * 2024-9-20:一刷,一开始没思路,看了题解.题目只要求了时间复杂度,没要求空间复杂度,要注意
 */
#include <vector>
#include <math.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        
        for (auto i : nums)
            res.push_back(0);

        int cur = res.size() - 1;
        while (cur>=0)
        {
            if (abs(nums[left]) < abs(nums[right]))
            {
                res[cur] = nums[right] * nums[right];
                --right;
                --cur;
            }
            else
            {
                res[cur] = nums[left] * nums[left];
                ++left;
                --cur;
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector<int> a = {-4,-1,0,3,10};
    auto res = s.sortedSquares(a);
    return 0;
}