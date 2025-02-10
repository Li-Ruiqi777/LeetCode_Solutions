/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit;
        for(int i=0;i<prices.size()-1;++i)
        {
            profit.push_back(prices[i+1] - prices[i]);
        }
        int sum = 0;
        for(auto i:profit){
            if(i>0)
                sum += i;
        }
        return sum;
    }
};
// @lc code=end

