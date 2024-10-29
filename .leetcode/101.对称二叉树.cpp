/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 * 一刷:2024-10-27,用的层序遍历法写出来的,但代码随想录用的是递归或者迭代法
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
    // bool isSymmetric(TreeNode *root)
    // {
    //     if (root == nullptr)
    //     {
    //         return false;
    //     }

    //     std::queue<TreeNode *> que;
    //     que.push(root);
    //     while (!que.empty())
    //     {
    //         int sz = que.size();
    //         std::vector<int> vec;

    //         for (int i = 0; i < sz; ++i)
    //         {
    //             auto node = que.front();
    //             que.pop();
    //             if (node != nullptr)
    //             {
    //                 vec.push_back(node->val);
    //                 que.push(node->left);
    //                 que.push(node->right);
    //             }

    //             else
    //                 vec.push_back(-9999);
    //         }

    //         if ((vec.size() > 1) && (vec.size() % 2 != 0))
    //             return false;

    //         std::vector<int> vec_reverse = vec;
    //         std::reverse(vec_reverse.begin(), vec_reverse.end());
    //         for (int i = 0; i < vec.size(); ++i)
    //         {
    //             if (vec_reverse[i] != vec[i])
    //                 return false;
    //         }
    //     }
    //     return true;
    // }

    // 通过递归法写出来
    bool compare(TreeNode *left,TreeNode *right)
    {
        if(left!=nullptr && right==nullptr) return false;
        else if(left==nullptr && right!=nullptr) return false;
        else if(left==nullptr && right==nullptr) return true;
        else if(left->val!=right->val) return false;

        bool outSide = compare(left->left,right->right);
        bool inSide = compare(left->right,right->left);
        return outSide && inSide;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return false;
        }

        return compare(root->left,root->right);
    }
};
// @lc code=end
