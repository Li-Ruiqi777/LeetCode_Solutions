/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 * 一刷:2024-10-30,看了题解.这题用了回溯法,回溯算法是一种通过搜索所有可能的解来解决问题的算法
 * 它的核心思想是 逐步构建解空间，如果发现当前构建的解不能满足要求，便回退一步，重新尝试其他可能性
 */

#include <vector>
#include <queue>
#include <string>
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
    void traverse(TreeNode *cur, std::vector<int> &path, vector<string> &result)
    {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr)
        {
            std::string sPath;
            for (auto i : path)
            {
                sPath += to_string(i);
                sPath += "->";
            }
            sPath.pop_back();
            sPath.pop_back();
            result.push_back(sPath);
            return;
        }
        if (cur->left)
        {
            traverse(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right)
        {
            traverse(cur->right, path, result);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        std::vector<int> path;
        vector<string> result;
        if(root==nullptr)
            return result;
        traverse(root,path,result);
        return result;
    }
};
// @lc code=end
