/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 * 一刷:2024-11-4
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;

        // 找最大的节点
        int max = -1;
        int maxIndex = -1;
        for (int k = 0; k < nums.size(); ++k)
        {
            if (nums[k] > max)
            {
                max = nums[k];
                maxIndex = k;
            }
        }

        TreeNode *root = new TreeNode(max);

        // 叶子节点就直接返回
        if (nums.size() == 1)
            return root;

        vector<int> left_nums;
        vector<int> right_nums;
        // 切分左半部
        int i;
        for (i = 0; i < maxIndex; ++i)
        {
            left_nums.push_back(nums[i]);
        }

        // 切分右半部
        for (i = maxIndex + 1; i < nums.size(); ++i)
        {
            right_nums.push_back(nums[i]);
        }

        // 递归赋值左右子树
        if (maxIndex >= 0)
            root->left = constructMaximumBinaryTree(left_nums);
        if (maxIndex < nums.size() - 1)
            root->right = constructMaximumBinaryTree(right_nums);

        return root;
    }
};
// @lc code=end
