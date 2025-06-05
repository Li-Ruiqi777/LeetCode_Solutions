/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 * 一刷:2024-9-26.用hashmap暴力写的,空间复杂度比较高
 */
#include <unordered_map>
#include <iostream>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* result = nullptr;
        int lenA = 0;
        int lenB = 0;
        auto cur = headA;
        while (cur != nullptr)
        {
            ++lenA;
            cur = cur->next;
        }
        cur = headB;
        while (cur != nullptr)
        {
            ++lenB;
            cur = cur->next;
        }

        if (lenA > lenB)
        {
            int slow = lenA - lenB;
            for (int i = 0; i < slow; ++i)
                headA = headA->next;
        }

        else
        {
            int slow = lenB - lenA;
            for (int i = 0; i < slow; ++i)
                headB = headB->next;
        }


        while(headA!=nullptr && headB!=nullptr)
        {
            if(headA == headB)
            {
                result = headA;
                break;
            }
            headA = headA->next;
            headB = headB->next;
                
        }
        return result;
    }
};
// @lc code=end

// 测试用例
void testGetIntersectionNode()
{
    Solution solution;

    // 创建两个相交的链表
    ListNode *common = new ListNode(8);
    common->next = new ListNode(9);
    common->next->next = new ListNode(10);

    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common; // A链表交点

    ListNode *headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = common; // B链表交点

    ListNode *intersection = solution.getIntersectionNode(headA, headB);

    // 输出测试结果
    if (intersection != nullptr)
    {
        std::cout << "Intersection Node Value: " << intersection->val << std::endl; // 应该输出8
    }
    else
    {
        std::cout << "No Intersection" << std::endl; // 不应该输出这个
    }

    // 释放内存
    delete common->next->next;      // 10
    delete common->next;            // 9
    delete common;                  // 8
    delete headA->next->next->next; // 3
    delete headA->next->next;       // 2
    delete headA->next;             // 1
    delete headA;                   // 1
    delete headB->next->next;       // 5
    delete headB->next;             // 4
    delete headB;                   // 4
}

int main()
{
    testGetIntersectionNode();
    return 0;
}