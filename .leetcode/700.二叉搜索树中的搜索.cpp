/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
 * 一刷:2024-11-5,看了题解
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
    // 递归法
    // TreeNode *searchBST(TreeNode *root, int val)
    // {
    //     if (root == nullptr || root->val == val)
    //         return root;
    //     TreeNode *res;
    //     if (root->val < val)
    //         res = searchBST(root->right, val);
    //     else if (root->val > val)
    //         res = searchBST(root->left, val);

    //     return res;
    // }

    // 迭代法
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val)
            return root;
        while (root != nullptr)
        {
            if(val > root->val) root = root->right;
            else if (val < root->val) root = root->left;
            else
                return root;
        }
        return nullptr;
    }
};
// @lc code=end
