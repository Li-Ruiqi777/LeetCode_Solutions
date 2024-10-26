/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 * 一刷:2024-10-26
 */

#include <vector>
#include <queue>
#include <cassert>
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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        std::queue<TreeNode *> que;
        que.push(root);

        int k = 1;
        while (!que.empty())
        {
            int sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                auto node = que.front();
                que.pop();

                if ((node->left==nullptr) && (node->right==nullptr))
                {
                    return k;
                }
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            ++k;
        }
        return k;
    }
};
// @lc code=end

TreeNode* buildTree(const std::vector<int>& values) {
    if (values.empty()) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    
    for (size_t i = 1; i < values.size(); ) {
        TreeNode* currentNode = nodeQueue.front();
        nodeQueue.pop();

        // 处理左子节点
        if (i < values.size() && values[i] != NULL) {
            currentNode->left = new TreeNode(values[i]);
            nodeQueue.push(currentNode->left);
        }
        i++;

        // 处理右子节点
        if (i < values.size() && values[i] != NULL) {
            currentNode->right = new TreeNode(values[i]);
            nodeQueue.push(currentNode->right);
        }
        i++;
    }

    return root;
}

void testMinDepth()
{
    Solution solution;

    // Edge case: Tree with only one leaf node
    std::vector<int> values = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode* root = buildTree(values);
    assert(solution.minDepth(root) == 1); // Depth should be 2
    delete root->left->right;             // Clean up
    delete root->left;
    delete root;

    // Clean up completed
}

int main()
{
    testMinDepth();
    return 0;
}