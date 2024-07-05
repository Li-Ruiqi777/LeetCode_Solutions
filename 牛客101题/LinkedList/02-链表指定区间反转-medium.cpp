// 一刷: 2024-7-5, 解题思路: 找到子区间和子区间的前、后Node,反转子区间再重新连接

#include <stack>
class Solution {
  public:

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        std::stack<ListNode*> stk;

        ListNode* p = head;
        while (p->next != nullptr) {
            stk.push(p);
            p = p->next;
        }
        ListNode* newHead = p;

        while (!stk.empty()) {
            ListNode* top = stk.top();
            p->next = top;
            p = p->next;
            top->next = nullptr;
            stk.pop();
        }
        return newHead;
    }


    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if (head == nullptr)
            return nullptr;
        if (m == n)
            return head;

        ListNode* subList = head;
        ListNode* pre = nullptr;   //子链表的上一个节点
        ListNode* next = nullptr;  //子链表的下一个节点

        int i = 1;
        ListNode* p = head;
        // 找subList
        while (p != nullptr) {
            if (i == m - 1)
                pre = p;

            else if (i == m)
                subList = p;

            if (i == n && p->next != nullptr) {
                next = p->next;
                p->next = nullptr;
            }


            ++i;
            p = p->next;
        }

        if (pre == nullptr) {
            subList = reverseList(subList);

            p = subList;
            while (p->next != nullptr) {
                p = p->next;
            }
            if(next != nullptr)
                p->next = next;
            return subList;
        }

        pre->next = nullptr;
        subList = reverseList(subList);

        pre->next = subList;
        p = subList;
        while (p->next != nullptr) {
            p = p->next;
        }
        if(next != nullptr)
            p->next = next;

        return head;

    }
};