/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 * 一刷:2024-11-3: 后序遍历数组的最后一个元素肯定是根节点, 可以根据这个来拆分中序数组
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
    TreeNode *traverse(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
            return nullptr;

        int rootValue = postorder.back();

        TreeNode *root = new TreeNode(rootValue);
        if (postorder.size() == 1)
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

        // 切分后序数组
        vector<int> postorder_left, postorder_right;
        for (i = 0; i < inorder_left.size(); ++i)
        {
            postorder_left.push_back(postorder[i]);
        }
        for (; i < postorder.size(); ++i)
        {
            postorder_right.push_back(postorder[i]);
        }
        postorder_right.pop_back();

        root->left = traverse(inorder_left, postorder_left);
        root->right = traverse(inorder_right, postorder_right);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0)
            return nullptr;
        return traverse(inorder, postorder);
    }
};
// @lc code=end
