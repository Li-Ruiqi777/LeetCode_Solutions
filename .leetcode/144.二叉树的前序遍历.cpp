/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 * 一刷:2024-10-20
 */
#include <vector>
#include <stack>
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
    // void traverse(TreeNode *cur,std::vector<int>& res)
    // {
    //     if(cur==nullptr)
    //         return;
    //     res.push_back(cur->val);
    //     traverse(cur->left,res);
    //     traverse(cur->right,res);
    // }

    // vector<int> preorderTraversal(TreeNode *root)
    // {
    //     std::vector<int> result;
    //     if(root == nullptr)
    //         return result;
    //     this->traverse(root,result);

    //     return result;
        
    // }

    // 迭代法
    vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        std::stack<TreeNode*> stk;

        if(root == nullptr)
            return result;

        stk.push(root);
        while(!stk.empty())
        {
            auto cur = stk.top();
            stk.pop();
            result.push_back(cur->val);
            if(cur->right) stk.push(cur->right);
            if(cur->left) stk.push(cur->left);
        }

        return result;
        
    }
};
// @lc code=end
