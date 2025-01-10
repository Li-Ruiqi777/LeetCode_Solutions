/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
private:
    vector<vector<string>> result;

    bool isValid(int row, int col, vector<string> &chessboard)
    {
        // 45度对角线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        // 135度对角线
        for (int i = row - 1, j = col + 1; i >= 0 && j < chessboard.size(); --i, ++j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        // 检查列
        for (int i = 0; i < row; ++i)
        {
            if (chessboard[i][col] == 'Q')
                return false;
        }
        return true;
    }

    void backtrack(int n, int row, vector<string> &chessboard)
    {
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            if (!isValid(row, col, chessboard))
                continue;
            chessboard[row][col] = 'Q';
            backtrack(n, row + 1, chessboard);
            chessboard[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtrack(n, 0, chessboard);
        return result;
    }
};
// @lc code=end
