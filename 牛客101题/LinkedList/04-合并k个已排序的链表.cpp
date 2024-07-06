//1刷：2024-7-6，思路：引入一个新的数组，先遍历所有链表，把节点中的值存到数组里，然后对数组排序
//再遍历排序后的数组，创建新的链表返回

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <vector>
#include "algorithm"
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param lists ListNode类vector 
     * @return ListNode类
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // write code here
        std::vector<int> arr;
        for(auto&& list : lists)
        {
            while(list !=nullptr)
            {
                arr.push_back(list->val);
                list = list->next;
            }
        }
        std::sort(arr.begin(),arr.end());
        ListNode* cur = new ListNode(-1);
        ListNode* newHead = cur;

        for(auto i:arr)
        {
            ListNode* temp = new ListNode(i);
            temp->next = nullptr;
            cur->next = temp;
            cur = cur->next; 
        }
        return newHead->next;
        
    }
};
