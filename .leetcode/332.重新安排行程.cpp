/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
private:
    unordered_map<string, map<string, int>> targets;
    vector<string> path;
    bool backtrack(int tickesNum)
    {
        if (path.size() == tickesNum + 1)
            return true;

        for (auto &target : targets[path.back()])
        {
            if (target.second <= 0)
                continue;

            path.push_back(target.first);
            target.second--;
            if (backtrack(tickesNum))
                return true;
            path.pop_back();
            target.second++;    
        }

        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto& ticket : tickets)
        {
            targets[ticket[0]][ticket[1]]++;
        }
        path.push_back("JFK");
        backtrack(tickets.size());
        return path;
    }
};
// @lc code=end
