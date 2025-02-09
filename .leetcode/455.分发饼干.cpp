/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        int index = 0;
        for(int i=0; i<g.size(); ++i){
            if(index < s.size() && s[index] >= g[i]){
                index++;
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

