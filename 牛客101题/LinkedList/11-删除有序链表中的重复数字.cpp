// 一刷：2024-7-11，这题第一眼看到感觉用个集合直接秒了，但是空间复杂度为O(n)，进阶点就双指针的写法，空间复杂度为O(1),
// 我这个题的逻辑是：如果当前指针和下一个值相等，就一直移动下一个，直到与当前指针的值不等

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(!head)
            return nullptr;
        
        auto p = head;

        while(p->next)
        {
            int prev = p->val;
            int next = p->next->val;
            if(prev != next)
            {
                p = p->next;
            }
            else 
            {
                auto pp = p->next->next;
                if(!pp)
                {
                    p->next = nullptr;
                   break;
                }
                    
                while(pp)
                {
                    if(pp->val != prev)
                        break;
                    pp = pp->next;
                }
                    
                p->next = pp;
            }

        }

        return head;
    }
};