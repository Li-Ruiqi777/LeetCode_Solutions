/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 * 一刷:2024-10-18:没写出来,之前不知道什么是单调队列
 */
#include <vector>
#include <deque>
using namespace std;

// @lc code=start
class Solution
{
private:
    // 单调(递增)队列,队头是队列中当前最大值,队头后面是后续可能成为最大值的值,整个队列是单调的
    class HumdrumQueue
    {
    private:
        std::deque<int> que;

    public:
        void pop(int value)
        {
            if (!que.empty() && value == que.front())
                que.pop_front();
        }

        void push(int value)
        {
            while (!que.empty() && value > que.back())
                {que.pop_back();}
            que.push_back(value);
        }

        int front()
        {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        HumdrumQueue que;
        std::vector<int> result;
        for (int i = 0; i < k; ++i)
        {
            que.push(nums[i]);
        }
        result.push_back(que.front());

        for (int i = k; i < nums.size(); ++i)
        {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
// @lc code=end
