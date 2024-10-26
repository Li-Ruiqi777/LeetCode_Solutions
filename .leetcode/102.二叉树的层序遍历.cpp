/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 * 一刷:2024-10-22：没写出来,看了题解
 */
#include <vector>
#include <queue>
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
    // vector<vector<int>> levelOrder(TreeNode *root)
    // {
    //     std::vector<std::vector<int>> result;
    //     if (root == nullptr)
    //         return result;
    //     std::queue<TreeNode *> que;
    //     que.push(root);
    //     while (!que.empty())
    //     {
    //         int sz = que.size();
    //         std::vector<int> temp;
    //         for (int i = 0; i < sz; ++i)
    //         {
    //             TreeNode *node = que.front();
    //             que.pop();
    //             temp.push_back(node->val);
    //             if(node->left) que.push(node->left);
    //             if(node->right) que.push(node->right);
    //         }
    //         result.push_back(temp);
    //     }
    //     return result;
    // }
    void order(TreeNode *cur, vector<vector<int>> &result, int depth)
    {
        if (cur == nullptr)
            return;
        if (depth == result.size())
            result.push_back({});
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        if (root == nullptr)
            return result;

        int depth = 0;
        this->order(root, result, depth);

        return result;
    }
};
// @lc code=end
