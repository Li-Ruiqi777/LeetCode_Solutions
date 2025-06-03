/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        bool result = false;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = 0;
        int j = cols - 1;
        while (i <= rows - 1 && j >= 0)
        {
            if (target == matrix[i][j])
                return true;

            else if(target > matrix[i][j])
                ++i;
            else
                --j;
        }
        return result;
    }
};
// @lc code=end
