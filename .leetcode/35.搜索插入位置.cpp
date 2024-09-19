/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;
        if (target > (nums[nums.size() - 1]))
            return nums.size();

        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                return mid;
        }

        if (nums[mid] < target)
            return mid + 1;
        else
            return mid;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector test = {1, 3, 5, 6};
    int k = s.searchInsert(test, 2);
    int a;
}