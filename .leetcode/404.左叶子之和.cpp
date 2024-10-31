/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 * 一刷:2024-10-31
 */

#include <vector>
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
    void traverse(TreeNode *parent, TreeNode *cur, int &sum)
    {
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (cur == parent->left)
                sum += cur->val;
            return;
        }
        if (cur->left)
            traverse(cur, cur->left, sum);
        if (cur->right)
            traverse(cur, cur->right, sum);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int sum = 0;

        if (root->left)
            traverse(root, root->left, sum);
        if (root->right)
            traverse(root, root->right, sum);

        return sum;
    }
};
// @lc code=end
