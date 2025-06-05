/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 * 二刷:2024-9-23:用双指针法没写出来，感觉老搞不清楚循环的退出条件
 * 三刷:2024-10-13:这题不需要搞虚拟头结点,或者说满指针初始值为null就是虚拟头结点了,不用单独再创一个
 */

#include <cassert>
#include <iostream>
#include <initializer_list>

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
        if(head == nullptr)
            return nullptr;
        auto cur = head;
        auto next = cur->next;
        while(next != nullptr)
        {
            auto temp = next->next; //保存下一个节点

            next->next = cur;//反转指针
            if(cur == head)
                cur->next = nullptr;
            cur = next;

            next = temp;

        }
        return cur;
    }
};
// @lc code=end

// Helper function to create a linked list from an initializer_list
ListNode *createList(std::initializer_list<int> values)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int value : values)
    {
        ListNode *newNode = new ListNode(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Helper function to verify the list content
void verifyList(ListNode *head, std::initializer_list<int> expected)
{
    for (int value : expected)
    {
        assert(head != nullptr && head->val == value);
        head = head->next;
    }
    assert(head == nullptr);
}

int main()
{
    Solution solution;

    // Happy path
    ListNode *list1 = createList({1, 2, 3, 4, 5});
    ListNode *reversed1 = solution.reverseList(list1);
    verifyList(reversed1, {5, 4, 3, 2, 1});

    // Edge case: Empty list
    ListNode *list2 = nullptr;
    ListNode *reversed2 = solution.reverseList(list2);
    assert(reversed2 == nullptr);

    // Edge case: Single element list
    ListNode *list3 = createList({1});
    ListNode *reversed3 = solution.reverseList(list3);
    verifyList(reversed3, {1});

    // Edge case: Two elements list
    ListNode *list4 = createList({1, 2});
    ListNode *reversed4 = solution.reverseList(list4);
    verifyList(reversed4, {2, 1});

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
