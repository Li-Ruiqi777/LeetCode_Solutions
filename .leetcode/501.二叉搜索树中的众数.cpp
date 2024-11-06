/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 * 一刷:2024-11-6,用哈希表来保存各个数字的出现频率,再对其排序求出频率最高的
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void traverse(TreeNode *cur)
    {
        if (!cur)
            return;
        this->num_freq[cur->val]++;
        traverse(cur->left);
        traverse(cur->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        traverse(root);
        std::vector<std::pair<int, int>> ordered_num_freq(num_freq.begin(), num_freq.end());
        std::sort(ordered_num_freq.begin(), ordered_num_freq.end(), [](const auto &a, const auto &b)
                  { return a.second > b.second; });

        std::vector<int> res;
        if(ordered_num_freq.size()==0)
            return res;
            
        res.push_back(ordered_num_freq[0].first);

        for (int i = 1; i < ordered_num_freq.size(); ++i)
        {
            if(ordered_num_freq[i].second == num_freq[res.front()])
                res.push_back(ordered_num_freq[i].first);
        }

        return res;
    }
    std::unordered_map<int, int> num_freq;
};
// @lc code=end
