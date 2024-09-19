/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left_border = getLeftBorder(nums, target);
        int right_border = getRightBorder(nums, target);

        if (left_border == -2 || right_border == -2)
            return {-1, -1};
        else if (right_border - left_border > 1)
            return {left_border + 1, right_border - 1};
        return {-1, -1};
    }

    int getLeftBorder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int left_border = -2;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
                left_border = right;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left_border;
    }

    int getRightBorder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int right_border = -2;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target)
            {
                left = mid + 1;
                right_border = left;
            }
            else
            {
                right = mid - 1;
            }
        }
        return right_border;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector test = {5,7,7,8,8,10};
    auto k = s.searchRange(test,8);
    int a;
}