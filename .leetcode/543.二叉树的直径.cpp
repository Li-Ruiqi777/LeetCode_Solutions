/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
#include <vector>
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int max_depth = 0;
        int cur_depth = get_max_depth(root, max_depth);
        return max_depth;
    }

    int get_max_depth(TreeNode *cur, int &max_diameter)
    {
        if (!cur)
            return 0;
        int left_depth = get_max_depth(cur->left, max_diameter);
        int right_depth = get_max_depth(cur->right, max_diameter);
        max_diameter = std::max(left_depth + right_depth, max_diameter);
        return 1 + std::max(left_depth, right_depth);
    }
};
// @lc code=end
