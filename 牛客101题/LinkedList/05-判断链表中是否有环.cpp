// 一刷：2024-7-7，解题思路：有环就代表如果一直遍历此链表，会访问到同一个node.那么可以把所有
// node都存在集合中，访问新node之前先在集合中find一下，看先前有没有访问到该node，如果访问到了，
// 就说明有环

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        
        std::unordered_set<ListNode*> hashSet;
        while (head != nullptr) 
        {
            auto pos = hashSet.find(head);
            if(pos != hashSet.end())
            {
                return true;
            }
            hashSet.insert(head);
            head = head->next;
        }
        return false;
        
    }
};