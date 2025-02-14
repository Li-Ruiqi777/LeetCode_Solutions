/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        std::sort(people.begin(), people.end(), this->cmp);
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); ++i)
        {
            int pos = people[i][1];
            res.insert(res.begin() + pos, people[i]);
        }
        return res;
    }
};
// @lc code=end
