/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 * 一刷:2024-11-3: 前序遍历数组的第一个元素肯定是根节点, 可以根据这个来拆分中序数组
 */

#include <vector>
#include <queue>
#include <cassert>
#include <iostream>

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
    TreeNode *traverse(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return nullptr;

        int rootValue = preorder.front();
        TreeNode *root = new TreeNode(rootValue);
        if (preorder.size() == 0)
            return root;

        // 切分中序数组
        vector<int> inorder_left, inorder_right;
        int i;
        for (i = 0; i < inorder.size(); ++i)
        {
            if (inorder[i] == rootValue)
                break;
            inorder_left.push_back(inorder[i]);
        }
        for (i = i + 1; i < inorder.size(); ++i)
        {
            inorder_right.push_back(inorder[i]);
        }

        // 切分前序数组
        vector<int> preorder_left, preorder_right;
        for (i = 1; i <= inorder_left.size(); ++i)
        {
            preorder_left.push_back(preorder[i]);
        }
        for (; i < preorder.size(); ++i)
        {
            preorder_right.push_back(preorder[i]);
        }

        root->left = traverse(preorder_left, inorder_left);
        root->right = traverse(preorder_right, inorder_right);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return traverse(preorder, inorder);
    }
};
// @lc code=end
