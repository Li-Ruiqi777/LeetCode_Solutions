/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int left = 0;
        int right = x;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left)/2;
            long long temp = (long long)mid * mid;
            if (temp == x)
                return mid;
            else if (temp < x)
                left = mid + 1;
            else if (temp > x)
                right = mid - 1;
        }
        return right; //对应找不到平方根的时候
    }
};
// @lc code=end
