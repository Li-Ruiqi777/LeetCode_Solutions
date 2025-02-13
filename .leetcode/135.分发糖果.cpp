/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candy;
        for (int i = 0; i < ratings.size(); ++i)
        {
            candy.push_back(1);
        }

        for (int i = 0; i < ratings.size() - 1; ++i)
        {
            if (ratings[i] < ratings[i + 1])
                candy[i + 1] = candy[i] + 1;
        }

        for (int i = ratings.size() - 1; i > 0; --i)
        {
            if (ratings[i - 1] > ratings[i])
                candy[i - 1] = max(candy[i] + 1, candy[i - 1]);
        }

        int total = 0;
        for (auto i : candy)
            total += i;
        return total;
    }
};
// @lc code=end
