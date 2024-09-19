/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
        }
        if (left <= right)
            return mid;
        else
            return -1;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector test = {-1,0,3,5,9,12};
    int k = s.search(test,9);
    int a;
}