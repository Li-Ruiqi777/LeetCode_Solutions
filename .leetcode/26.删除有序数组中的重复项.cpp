/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 * 一刷:2024-9-18. 没写出来，之前没怎么写过快慢指针的题目。一般这种类型的题目，只需要写!=的情况？
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slowIdx=0;
        for(int fastIdx=1;fastIdx<nums.size();++fastIdx){
            if(nums[slowIdx]!=nums[fastIdx])
            {
                ++slowIdx;
                nums[slowIdx]=nums[fastIdx];
            }
        }
        return slowIdx+1;
    }
};
// @lc code=end

int main()
{
    vector<int> input = {1,1};
    Solution s;
    s.removeDuplicates(input);
    int k;
}
