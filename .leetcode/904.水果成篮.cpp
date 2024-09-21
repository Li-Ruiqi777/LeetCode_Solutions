/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 * 一刷: 2024-9-21,没写出来，这题用哈希表比较合适，但我第一思路是用集合，我那种方法
 * 属于是暴力解法，时间复杂度O(n^2)，超时了
 * 要注意：哈希表插入新元素有3种方法，不一定非要用pair
 * 滑动窗口一般拿右边界来循环而不是左边界，左边界就成暴力了
 */
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int left = 0;
        int ret = 0;
        std::unordered_map<int,int> count;
        for(int right = 0;right<fruits.size();++right)
        {
            ++count[fruits[right]];

            while(count.size()>2)
            {
                auto it = count.find(fruits[left]);
                --it->second;
                if(it->second == 0)
                    count.erase(fruits[left]);
                ++left;
            }

            ret = max(ret,right-left+1);

        }
        return ret;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector<int> input = {1,2,1};
    s.totalFruit(input);
    return 0;
}
