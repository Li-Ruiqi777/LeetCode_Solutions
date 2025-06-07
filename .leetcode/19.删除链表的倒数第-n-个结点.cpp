/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 * 一刷:2024-9-23:感觉挺简单的,但写了好久
 * 删掉倒数第n个==删掉正数第size-n个. 但这种写法需要遍历链表2次
 */
#include <iostream>
#include <cassert>
#include <vector>

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if(!head->next)
            return nullptr;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for(int i=0;i<n;++i)
        {
            fast = fast->next;
        }
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy.next;
    }
};
// @lc code=end

// Helper function to create a linked list from an array
ListNode *createLinkedList(const std::vector<int> &values)
{
    ListNode dummy;
    ListNode *current = &dummy;
    for (int value : values)
    {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy.next;
}

// Helper function to convert linked list to vector for easy comparison
std::vector<int> linkedListToVector(ListNode *head)
{
    std::vector<int> result;
    while (head)
    {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Unit tests
void testRemoveNthFromEnd()
{
    Solution solution;

    // Test case 2: Remove the head
    ListNode *head2 = createLinkedList({1, 2});
    ListNode *result2 = solution.removeNthFromEnd(head2, 2);
    assert(linkedListToVector(result2) == std::vector<int>({2}));

    // Test case 3: Single element list
    ListNode *head3 = createLinkedList({1});
    ListNode *result3 = solution.removeNthFromEnd(head3, 1);
    assert(result3 == nullptr);

    // Test case 4: Remove only node in a single node list
    ListNode *head4 = createLinkedList({10});
    ListNode *result4 = solution.removeNthFromEnd(head4, 1);
    assert(result4 == nullptr);

    // Test case 5: Removing from two element list
    ListNode *head5 = createLinkedList({1, 2});
    ListNode *result5 = solution.removeNthFromEnd(head5, 1);
    assert(linkedListToVector(result5) == std::vector<int>({1}));

    // Test case 6: Removing from a longer list
    ListNode *head6 = createLinkedList({1, 2, 3, 4, 5, 6, 7});
    ListNode *result6 = solution.removeNthFromEnd(head6, 4);
    assert(linkedListToVector(result6) == std::vector<int>({1, 2, 3, 5, 6, 7}));

    std::cout << "All test cases passed!" << std::endl;
}

int main()
{
    testRemoveNthFromEnd();
    return 0;
}