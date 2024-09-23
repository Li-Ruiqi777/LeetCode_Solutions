/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 * 一刷:2024-9-22:没写出来,链表删头结点要格外注意一下,
 * 可以弄个虚拟头结点,这样后边的所有节点的处理都一样了
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *newHead = new ListNode(0,head);
  
        ListNode *p = newHead;
        while (p->next != nullptr)
        {
            if(p->next->val == val)
            {
                auto temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else
                p = p->next;
        }
        return newHead->next;
    }
};
// @lc code=end
