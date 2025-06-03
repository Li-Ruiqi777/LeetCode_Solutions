/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <vector>
#include <set>
using namespace std;
// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> zero_rows;
        set<int> zero_cols;

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zero_rows.insert(i);
                    zero_cols.insert(j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if(zero_rows.count(i) > 0)
                    matrix[i][j] = 0;

                if(zero_cols.count(j) > 0)
                    matrix[i][j] = 0;
            }
        }
    }
};
// @lc code=end
