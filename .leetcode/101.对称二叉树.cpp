/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 * 一刷:2024-10-27,用的层序遍历法写出来的,但代码随想录用的是递归或者迭代法
 */

#include <vector>
#include <queue>
#include <stack>
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
    bool isSymmetric(TreeNode *root)
    {
        return compare(root->left, root->right);
    }

    bool compare(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        bool flag1 = left->val == right->val;
        bool flag2 = compare(left->left, right->right);
        bool flag3 = compare(left->right, right->left);
        return flag1 && flag2 && flag3;
    }
};
// @lc code=end
