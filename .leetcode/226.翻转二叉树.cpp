/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 * 一刷:2024-10-27,反转二叉树实际上就是对于每个节点都交换其左右孩子,不管是DFS还是BFS遍历都可以
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
    // 通过层序遍历实现
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root==nullptr)
    //     {
    //         return nullptr;
    //     }
    //     std::queue<TreeNode*> que;
    //     que.push(root);
    //     while(!que.empty())
    //     {
    //         int sz = que.size();
    //         for(int i=0;i<sz;++i)
    //         {
    //             auto node = que.front();
    //             que.pop();
    //             auto temp = node->left;
    //             node->left = node->right;
    //             node->right = temp;

    //             if(node->left) que.push(node->left);
    //             if(node->right) que.push(node->right);
    //         }
    //     }
    //     return root;
    // }

    // 通过递归遍历实现
    void traverse(TreeNode *cur)
    {
        if (cur == nullptr)
            return;

        auto temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;

        traverse(cur->left);
        traverse(cur->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        traverse(root);

        return root;
    }
};
// @lc code=end
