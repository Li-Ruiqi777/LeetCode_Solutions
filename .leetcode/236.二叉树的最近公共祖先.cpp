/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 * 一刷:2024-11-6,没看题解艰难写出来了,感觉时间复杂度那些的应该不太好
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void traverse(TreeNode *cur, int targetVal,
                  std::vector<TreeNode *> &path, std::vector<TreeNode *> &res)
    {
        if(!cur)
            return;
        path.push_back(cur);

        if (cur->val == targetVal)
        {
            res = std::vector(path.begin(), path.end());
            return;
        }

        if (cur->left)
        {
            traverse(cur->left, targetVal, path, res);
            path.pop_back();
        }
        if (cur->right)
        {
            traverse(cur->right, targetVal, path, res);
            path.pop_back();
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 1.分别找到root-->p和root-->q的路径
        std::vector<TreeNode *> path_p, path_q;
        traverse(root, p->val, path_p, res_path_p);
        traverse(root, q->val, path_q, res_path_q);

        std::cout << "-----------------" << std::endl;
        for (auto i : res_path_p)
        {
            std::cout << i->val << std::endl;
        }
        std::cout << "-----------------" << std::endl;
        for (auto i : res_path_q)
        {
            std::cout << i->val << std::endl;
        }

        // std::cout << "-----------------" << std::endl;
        // for (int i = res_path_p.size(); i > 0; --i)
        // {
        //     std::cout << res_path_p[i - 1]->val << std::endl;
        // }
        // std::cout << "-----------------" << std::endl;
        // for (int i = res_path_q.size(); i > 0; --i)
        // {
        //     std::cout << res_path_q[i - 1]->val << std::endl;
        // }


        TreeNode *res = nullptr;
        // 从右遍历路径,找最先出现的相同值
        if (res_path_p.size() <= res_path_q.size())
        {
            for (int i = res_path_p.size(); i > 0; --i)
            {
                for (int j = res_path_q.size(); j > 0; --j)
                {
                    if (res_path_p[i - 1]->val == res_path_q[j - 1]->val)
                    {
                        res = res_path_p[i - 1];
                        return res;
                    }
                        
                }
            }
        }

        else
        {
            for (int i = res_path_q.size(); i > 0; --i)
            {
                for (int j = res_path_p.size(); j > 0; --j)
                {
                    if (res_path_q[i - 1]->val == res_path_p[j - 1]->val)
                    {
                        res = res_path_q[i - 1];
                        return res;
                    }
                }
            }
        }
        return res;
    }

    std::vector<TreeNode *> res_path_p, res_path_q;
};
// @lc code=end
