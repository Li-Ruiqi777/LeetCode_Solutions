// 一刷:2024-7-9，没写出来，忘记了怎么提取出一个数的各位数字是什么了(先%10，再/10)，并且这题直接思路是对的，但是数太大了一直
// 溢出，没办法就换了个写法。
// !这种2个链表的题,优先想到用辅助链表的方法

/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        std::stack<int> stk1;
        std::stack<int> stk2;

        std::stack<int> stk3;

        while (head1) {
            stk1.push(head1->val);
            head1 = head1->next;
        }

        while (head2) {
            stk2.push(head2->val);
            head2 = head2->next;
        }

        int carry = 0;//进位
        while (!stk1.empty() || !stk2.empty()) {
            int num1 = 0;
            int num2 = 0;
            if (!stk1.empty()) {
                num1 = stk1.top();
                stk1.pop();
            }

            if (!stk2.empty()) {
                num2 = stk2.top();
                stk2.pop();
            }

            int sum = num1 + num2 + carry;
            carry = sum / 10;
            stk3.push(sum % 10);
        }
        if (carry != 0)
            stk3.push(carry);


        ListNode* vHead = new ListNode(-1);
        ListNode* p = vHead;
        p->next = nullptr;
        while (!stk3.empty()) {
            auto num = stk3.top();
            stk3.pop();
            ListNode* temp = new ListNode(num);
            temp->next = nullptr;
            p->next = temp;
            p = p->next;
        }

        return vHead->next;

    }
};