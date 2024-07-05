/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead1 ListNode类
     * @param pHead2 ListNode类
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) 
    {
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;

        ListNode* cur = nullptr;

        if(cur1 == nullptr)
            return cur2;
        else if(cur2 == nullptr)
            return cur1;

        ListNode* newHead = nullptr;
        if(cur1->val <= cur2->val)
        {
            cur = cur1;
            cur1 = cur1->next;
            cur->next = nullptr;
            newHead = cur;
        }

        else 
        {
            cur = cur2;
            cur2 = cur2->next;
            cur->next = nullptr;
            newHead = cur;
        }

        while (cur1 != nullptr && cur2 != nullptr) 
        {
            if(cur1->val <= cur2->val)
            {
                cur->next = cur1;
                cur = cur->next;

                cur1 = cur1->next;
                cur->next = nullptr;
            }
            else if(cur1->val > cur2->val)
            {
                cur->next = cur2;
                cur = cur->next;

                cur2 = cur2->next;
                cur->next = nullptr;
            }

        }

        if(cur1 == nullptr)
            cur->next = cur2;
        else
         cur->next = cur1;


        return newHead;
    }
};