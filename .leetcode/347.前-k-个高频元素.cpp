/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 * 一刷:2024-10-19:看了题解,这题用到了优先级队列(堆)这种数据结构,之前没接触过
 */
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    class myCompare
    {
    public:
        bool operator()(std::pair<int, int> l, std::pair<int, int> r)
        {
            return l.second > r.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, myCompare> pri_que;
        std::unordered_map<int, int> count;
        for (auto i : nums)
        {
            count[i]++;
        }

        for (auto &i : count)
        {
            pri_que.push(i);
            if (pri_que.size() > k)
                pri_que.pop();
        }

        std::vector<int> res;
        res.resize(pri_que.size());

        for (int i = pri_que.size()-1; i >=0; --i)
        {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};
// @lc code=end
