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
        vector<int> res;
        int u = 0;
        int b = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;

        while (1)
        {
            for (int i = l; i <= r; ++i)
                res.push_back(matrix[u][i]);
            if (++u > b)
                break;
            for (int i = u; i <= b; ++i)
                res.push_back(matrix[i][r]);
            if (--r < l)
                break;
            for (int i = r; i >= l; --i)
                res.push_back(matrix[b][i]);
            if (--b < u)
                break;
            for (int i = b; i >= u; --i)
                res.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }
        return res;
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
