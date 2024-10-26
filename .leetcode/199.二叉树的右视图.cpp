/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 * 一刷：2024-10-22
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
    vector<int> rightSideView(TreeNode *root)
    {
        std::vector<int> result;
        if (root == nullptr)
            return result;

        std::queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int sz = que.size();
            std::stack<int> temp;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                temp.push(node->val);
                if(node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                
            }
            if(!temp.empty())
                result.push_back(temp.top());
        }

        return result;
    }
};
// @lc code=end
