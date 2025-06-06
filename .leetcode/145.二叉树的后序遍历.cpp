/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 * 一刷:2024-10-20
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
class Solution {
public:
    void traverse(TreeNode *cur,std::vector<int>& res)
    {
        if(cur==nullptr)
            return;
        traverse(cur->left,res);
        traverse(cur->right,res);
        res.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        if(root == nullptr)
            return result;
        this->traverse(root,result);

        return result;
        
    }
};
// @lc code=end

