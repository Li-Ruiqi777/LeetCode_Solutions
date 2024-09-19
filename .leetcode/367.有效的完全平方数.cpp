/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 0)
            return true;
        int left = 0;
        int mid = 0;
        int right = num;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            long long temp = (long long)mid * mid;
            if (temp == num)
                return true;
            else if (temp < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
// @lc code=end
