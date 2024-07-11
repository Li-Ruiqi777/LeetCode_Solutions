//一刷：2024-7-11，用2个辅助队列直接秒了

/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <queue>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        // write code here
        int i = 1;
        std::queue<int> odd;
        std::queue<int> even;

        while (head) {
            if (i % 2 != 0) {
                odd.push(head->val);
            } else {
                even.push(head->val);
            }
            ++i;
            head = head->next;
        }

        auto vHead = new ListNode(-1);
        auto p = vHead;
        p->next = nullptr;
        while (!odd.empty()) {
            auto t = new ListNode(odd.front());
            odd.pop();
            t->next = nullptr;
            p->next = t;
            p = p->next;
        }
        while (!even.empty()) {
            auto t = new ListNode(even.front());
            even.pop();
            t->next = nullptr;
            p->next = t;
            p = p->next;
        }

        return vHead->next;
    }
};