/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 * 一刷:2024-10-28
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q != nullptr)
            return false;
        else if (p != nullptr && q == nullptr)
            return false;
        else if (p == nullptr && q == nullptr)
            return true;
        else if (p->val != q->val)
            return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right;
    }

    bool dfs(TreeNode *cur, TreeNode *subRoot)
    {
        if (cur == nullptr)
            return false;
        return isSameTree(cur, subRoot) ||
               dfs(cur->left, subRoot) ||
               dfs(cur->right, subRoot);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        return dfs(root,subRoot);
    }
};
// @lc code=end
