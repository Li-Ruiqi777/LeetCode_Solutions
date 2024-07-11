// 一刷：2024-7-11，判断回文结构需要分别从头和尾遍历一个链表，可以使用辅助的数据结构(一个栈一个队列做到)

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <queue>
#include <stack>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        std::stack<int> stk;
        std::queue<int> queue;

        while(head)
        {
            stk.push(head->val);
            queue.push(head->val);
            head = head->next;
        }

        while(!stk.empty())
        {
            int num1 = stk.top();
            stk.pop();
            int num2 = queue.front();
            queue.pop();
            if(num1 != num2)
                return false;
        }
        return true;
    }
};