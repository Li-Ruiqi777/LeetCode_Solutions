/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        auto end = reverseList(mid);
        while (end)
        {
            if (head->val != end->val)
                return false;
            head = head->next;
            end = end->next;
        }
        return true;
    }
};
// @lc code=end
