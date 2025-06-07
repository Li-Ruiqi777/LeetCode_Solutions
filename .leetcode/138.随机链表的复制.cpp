/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */
#include <unordered_map>

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
}

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    // 先遍历原链表同时创建复制链表,只有val和next,同时用hash表记录random的指向元素的idx
    // 再根据hash表给复制链表的random赋值
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        Node dummy(0);
        Node *tail = &dummy;
        Node *cur = head;
        std::unordered_map<Node *, int> index;

        while (cur)
        {
            Node *node = new Node(cur->val);
            tail->next = node;
            tail = tail->next;

            if (!cur->random)
            {
                std::pair<Node *, int> tmp(node, -1);
                index.insert(tmp);
            }
            else
            {
                int i = 0;
                Node *temp = head;
                while (temp != cur->random)
                {
                    temp = temp->next;
                    i++;
                }
                std::pair<Node *, int> tmp(node, i);
                index.insert(tmp);
            }
            cur = cur->next;
        }

        cur = dummy.next;
        while (cur)
        {
            int random_index = index[cur];
            if (random_index == -1)
                cur->random = nullptr;
            else
            {
                auto new_head = dummy.next;
                for (int i = 0; i < random_index; ++i)
                    new_head = new_head->next;

                cur->random = new_head;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end
