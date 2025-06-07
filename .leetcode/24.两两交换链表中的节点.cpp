/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 * 一刷:2024-9-23:没写出来
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
    ListNode *swapPairs(ListNode *head)
    {
        if(!(head && head->next))
            return head;

        ListNode* pre = head;
        ListNode* cur = head->next;

        ListNode* res = cur;

        while(pre && cur)
        {
            // 交换节点
            pre->next = cur->next;
            cur->next = pre;
            
            // 更新节点
            // pre = pre->next;
            cur = pre->next;
        }
        return res;
    
    }
};
// @lc code=end
