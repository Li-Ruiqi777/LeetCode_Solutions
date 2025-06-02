/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        
        int n = nums.size();

        vector<int> result(n, 1);
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for (int i = 1; i < n; ++i)
            left[i] = nums[i - 1] * left[i - 1];

        for (int i = n - 2; i >= 0; --i)
            right[i] = nums[i + 1] * right[i + 1];

        for (int i = 0; i < n; ++i)
            result[i] = left[i] * right[i];

        return result;
    }
};
// @lc code=end
