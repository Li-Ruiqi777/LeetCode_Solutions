// 一刷: 2024-7-3

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <stack>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        // write code here

        if(head == nullptr)
            return nullptr;

        std::stack<ListNode*> stack;
        ListNode* p = head;
        
        while(p->next != nullptr)
        {
            stack.push(p);
            p = p->next;
        }
        ListNode* new_head = p;

        while(!stack.empty())
        {
            ListNode* last = stack.top();
            last->next = nullptr;
            stack.pop();
            p->next = last;
            p = last;
        }
        return new_head;
    }
};