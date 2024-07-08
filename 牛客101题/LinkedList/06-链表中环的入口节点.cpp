// 一刷：2024-7-8. 解题思路，和05一样，用集合直接秒了

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
#include <unordered_set>
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        std::unordered_set<ListNode*> set;
        while(pHead)
        {
            if(set.find(pHead) != set.end())
            {
                auto pos = set.find(pHead);
                return *pos;
            }
            set.insert(pHead);
            pHead = pHead->next;
        }
        return nullptr;
    }
};