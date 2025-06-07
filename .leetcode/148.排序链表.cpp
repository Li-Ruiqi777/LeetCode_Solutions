/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
#include <vector>
#include <algorithm>
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
    ListNode *sortList(ListNode *head)
    {
        if(!head)
            return nullptr;
        ListNode* cur = head;
        std::vector<int> vals;
        while(cur)
        {
            vals.push_back(cur->val);
            cur = cur->next;
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;
        std::sort(vals.begin(), vals.end());
        for(int i=0;i<vals.size();++i)
        {
            ListNode* node = new ListNode(vals[i]);
            tail->next = node;
            tail = tail->next;
        }
        return dummy.next;

    }
};
// @lc code=end
