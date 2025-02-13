/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include <queue>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int num_5 = 0;
        int num_10 = 0;
        for (auto &bill : bills)
        {
            if (bill == 5)
                num_5++;
            if (bill == 10)
            {
                num_10++;
                num_5--;
                if (num_5 < 0)
                    return false;
            }
            if (bill == 20)
            {
                if(num_10 > 0)
                {
                    num_10--;
                    num_5--;
                }
                else
                {
                    num_5 -= 3;
                }
                
                if (num_5 < 0 || num_10 < 0)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
