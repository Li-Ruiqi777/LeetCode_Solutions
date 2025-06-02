/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            int sum = 0;
            for (int j = 1; j <= i; ++j)
            {
                sum += dp[j-1] * dp[i - j];
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};
// @lc code=end
