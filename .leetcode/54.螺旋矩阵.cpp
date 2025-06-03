/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 * 一刷:2024-9-22:没写出来,看了题解
 */

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int top_row = 0;
        int bottom_row = matrix.size() - 1;
        int left_col = 0;
        int right_col = matrix[0].size() - 1;
        vector<int> result;
        while (top_row <= bottom_row && left_col <= right_col)
        {
            for (int i = left_col; i <= right_col; ++i)
            {
                result.push_back(matrix[top_row][i]);
            }
            ++top_row;
            for (int i = top_row; i <= bottom_row; ++i)
            {
                result.push_back(matrix[i][right_col]);
            }
            --right_col;
            
            if (top_row <= bottom_row)
            {
                for (int i = right_col; i >= left_col; --i)
                {
                    result.push_back(matrix[bottom_row][i]);
                }
                --bottom_row;
            }

            if (left_col <= right_col)
            {
                for (int i = bottom_row; i >= top_row; --i)
                {
                    result.push_back(matrix[i][left_col]);
                }
                ++left_col;
            }
        }
        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{6, 9, 7}};
    s.spiralOrder(matrix);
    return 0;
}
