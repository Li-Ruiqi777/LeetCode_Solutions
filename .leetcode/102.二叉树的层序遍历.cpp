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

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        if (root == nullptr)
            return result;
        std::queue<TreeNode *> que;
        que.push(root);
        while(!que.empty())
        {
            std::vector<int> temp;
            int size = que.size();
            for(int i =0;i<size;++i)
            {
                auto node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(temp);
        }
        return result;
    }
};
// @lc code=end
