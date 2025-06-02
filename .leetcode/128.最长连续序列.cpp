/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 * 2025-4-14:一刷,看了题解,体会到了set/unordered_set遍历底层数据结构不同带来的区别:for遍历时
 * 得到元素的顺序不同
 */
#include <vector>
#include <unordered_set>

#include <queue>
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int max_length = 0;
        for (int num : set)
        {
            if (set.count(num - 1) == 0)
            {
                int current_num = num;
                int current_len = 1;

                while(set.count(current_num+1) != 0){
                    current_num++;
                    current_len++;
                }
                max_length = max(current_len,max_length);
            }
        }
        return max_length;
    }
};
// @lc code=end
