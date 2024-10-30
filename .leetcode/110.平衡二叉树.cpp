/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 * 一刷:2024-10-30,看了题解.平衡二叉树是左右子树高度差不超过1的二叉树
 * 求二叉树的高度时,一般用后续遍历
 */

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int getHeight(TreeNode *cur)
    {
        if (cur == nullptr)
            return 0;
        int left = getHeight(cur->left);
        int right = getHeight(cur->right);
        if (left == -1 || right == -1)
            return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return getHeight(root) == -1 ? false : true;
    }
};
// @lc code=end
