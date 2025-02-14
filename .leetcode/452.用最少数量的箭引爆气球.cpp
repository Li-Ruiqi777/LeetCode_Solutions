/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    static bool cmp(const vector<int> &left, const vector<int> &right)
    {

        if (left[0] == right[0])
            return (left[1] < right[1]);
        return left[0] < right[0];
    }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        std::sort(points.begin(), points.end(), cmp);
        int num = 1;
        for (int i = 0; i < points.size() - 1; ++i)
        {
            // 不挨着
            if (points[i][1] < points[i + 1][0])
                num++;
            // 挨着:更新右边界
            else
            {
                points[i + 1][1] = min(points[i + 1][1], points[i][1]);
            }
        }
        return num;
    }
};
// @lc code=end
