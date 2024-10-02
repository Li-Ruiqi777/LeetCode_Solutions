/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 * 一刷:2024-9-26:看了题解才写出来的.先求相遇点,然后再求相交点就是环节点
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;

        if(!head)
            return nullptr;

        while(fast!=nullptr&&fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow)
            {
                auto index1 = head;
                auto index2 = fast;
                while(index1 != index2)
                {       
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
// @lc code=end

