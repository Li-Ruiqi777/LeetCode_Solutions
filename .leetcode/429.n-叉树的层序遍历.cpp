/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 * 一刷:2024-10-22
 */

#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        std::vector<std::vector<int>> result;
        if(root==nullptr)
            return result;
        
        std::queue<Node*> que;
        que.push(root);

        while(!que.empty())
        {
            int sz = que.size();
            std::vector<int> temp;
            for(int i=0;i<sz;++i)
            {
                auto node = que.front();
                que.pop();
                temp.push_back(node->val);
                for(auto i:node->children)
                    que.push(i);
                
            }
            
            result.push_back(temp);
        }
        return result;
    }
};
// @lc code=end
