/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.44%)
 * Likes:    1711
 * Dislikes: 0
 * Total Accepted:    812.9K
 * Total Submissions: 1M
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> results;
    void back_track(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            results.push_back(path);
            return;
        }
        // 已经走过的节点个数:path.size()
        // 剩余没走的节点个数:k-path.size()
        // 最大开始位置:n - (k - path.size()) + 1
        for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i)
        {
            path.push_back(i);
            back_track(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        back_track(n, k, 1);
        return results;
    }
};
// @lc code=end
