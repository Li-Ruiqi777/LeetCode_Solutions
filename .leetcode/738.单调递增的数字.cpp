/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string num_str = std::to_string(n);
        int change_idx = num_str.size();

        for (int i = num_str.size() - 1; i > 0; --i)
        {
            if (num_str[i] < num_str[i - 1])
            {
                change_idx = i;
                num_str[i-1]--;
            }
        }
        for (int i = change_idx; i < num_str.size(); ++i)
            num_str[i] = '9';
        return stoi(num_str);
    }
};
// @lc code=end
