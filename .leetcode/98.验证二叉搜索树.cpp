/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 * 一刷:2024-11-5,看了题解感觉用中序遍历添加到数组还是比较简单的,递归法太绕了
 * 之前对于BST的定义有误解,左子树的所有元素都得小于根节点、右子树的所有元素都得大于根节点
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
    bool isValidBST(TreeNode *root)
    {
        std::vector<int>nums;
        traverse(root, nums);
        for(int i=1; i<nums.size();++i)
        {
            if(nums[i-1]>=nums[i])
                return false;
        }  
        return true;
    }

    void traverse(TreeNode *cur, std::vector<int>& nums)
    {
        if(!cur)
            return;
        traverse(cur->left, nums);
        nums.push_back(cur->val);
        traverse(cur->right, nums);
    }
};
// @lc code=end
