/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 * 一刷:2024-11-1,注意递归函数什么时候有返回值,什么时候没有返回值（如果要遍历所有路径就不需要返回值,如果只找到一条路径就结束的话,就需要返回值）
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
    void traverse(TreeNode *cur, int count)
    {
        if (!cur->left && !cur->right && count == cur->val)
        {
            result.push_back(temp_result);
        }
        else if (cur->left || cur->right)
        {
            if (cur->left)
            {
                count -= cur->val;
                temp_result.push_back(cur->left->val);
                traverse(cur->left, count);
                temp_result.pop_back();
                count += cur->val;
            }
            if (cur->right)
            {
                count -= cur->val;
                temp_result.push_back(cur->right->val);
                traverse(cur->right, count);
                temp_result.pop_back();
                count += cur->val;
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return result;
        temp_result.push_back(root->val);
        traverse(root, targetSum);
        return result;
    }

    vector<vector<int>> result;
    vector<int> temp_result;
};
// @lc code=end
