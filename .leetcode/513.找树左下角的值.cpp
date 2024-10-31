/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 * 一刷:2024-10-31,这题用层序遍历直接秒了,为了练习递归,这题用的递归法写的
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
    void traverse(TreeNode *cur, int &curDepth)
    {
        if (cur == nullptr)
            return;
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (curDepth > this->maxDepth)
            {
                this->maxDepth = curDepth;
                this->DepthestNode = cur;
            }
        }
        if (cur->left)
        {
            curDepth += 1;
            traverse(cur->left, curDepth);
            curDepth -= 1;
        }
        if (cur->right)
        {
            curDepth += 1;
            traverse(cur->right, curDepth);
            curDepth -= 1;
        }
    }

    int findBottomLeftValue(TreeNode *root)
    {
        DepthestNode = root;
        this->maxDepth = 0;
        if (root == nullptr)
            return 0;
        int depth = 0;
        this->traverse(root, depth);
        return DepthestNode->val;
    }
    int maxDepth;
    TreeNode *DepthestNode;
};
// @lc code=end
