/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 * 一刷:2024-11-6. 因为二叉搜索树可以转换为一个升序数组,所以按这个思路其实就是求升序数组中的最小绝对差,暴力就行了
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
    void traverse(TreeNode *cur, std::vector<int>& vec)
    {
        if (!cur)
            return;
        traverse(cur->left, vec);
        vec.push_back(cur->val);
        traverse(cur->right, vec);
    }

    int getMinimumDifference(TreeNode *root)
    {
        std::vector<int> vec;
        traverse(root, vec);

        int minSub = INT_MAX;
        for (int i = 1; i < vec.size(); ++i)
        {
            int sub = abs(vec[i] - vec[i - 1]);
            if (sub < minSub)
                minSub = sub;
        }
        return minSub;
    }
};
// @lc code=end
