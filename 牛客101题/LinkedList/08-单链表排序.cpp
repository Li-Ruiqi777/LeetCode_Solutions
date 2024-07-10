// 一刷:2024-7-10,这题就创建个数组，先把链表的值全部存到数组里，然后对数组排序，再由该数组构造新链表返回

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // write code here
        std::vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            auto temp = head;
            head = head->next;
            delete temp;
        }
        std::sort(vec.begin(),vec.end(),[](int a,int b){
            return a > b;
        });
        ListNode* vHead = new ListNode(-1);
        ListNode* p = vHead;
        p->next = nullptr;

        while(!vec.empty())
        {
            ListNode* temp = new ListNode(vec[vec.size()-1]);
            vec.pop_back();
            p->next = temp;
            temp->next = nullptr;
            p = p->next;
        }

        return vHead->next;
    }
};