/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> matrix_copy = matrix;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = i; j < cols; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols / 2; ++j)
            {
                swap(matrix[i][j], matrix[i][cols-1 - j]);
            }
        }
    }
};
// @lc code=end
