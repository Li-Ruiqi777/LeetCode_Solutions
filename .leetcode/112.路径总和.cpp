/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 * 2024-11-1:一刷
 */

#include <vector>
#include <queue>
#include <cassert>
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
    bool traverse(TreeNode *cur, int count)
    {
        if (cur->left == nullptr && cur->right == nullptr && count == cur->val)
            return true;
        else if (cur->left == nullptr && cur->right == nullptr)
            return false;


        if (cur->left)
        {
            count -= cur->val;
            if(traverse(cur->left, count))  return true;
            count += cur->val;
        }
        if (cur->right)
        {
            count -= cur->val;
            if(traverse(cur->right, count))  return true;
            count += cur->val;
        }
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        return traverse(root,targetSum);
    }
};
// @lc code=end
