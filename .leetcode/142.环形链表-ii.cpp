/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 * 一刷:2024-9-26:看了题解才写出来的.先求相遇点,然后再求相交点就是环节点
 * 二刷:2024-10-13:写出来了,不过是背的
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
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *left = head;
        ListNode *right = head;

        while (right->next != nullptr && right->next->next != nullptr)
        {
            left = left->next;
            right = right->next->next;

            if(left == right){
                left = head;
                while(left!=right)
                {
                    left=left->next;
                    right = right->next;
                }
                return left;
            }
        }

        return nullptr;
    }
};
// @lc code=end
