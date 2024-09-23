/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 * 2024-9-22:一刷:没完全写出来,主要是get写的不好，应该用while(index--)来写而
 * 不是for循环
 */

// @lc code=start

struct LinkedNode
{
    int val;
    LinkedNode *next = nullptr;
    LinkedNode(int num) : val(num) {}
    LinkedNode() : val(0) {}
};

class MyLinkedList
{
public:
    MyLinkedList()
    {
        this->dummyHead = new LinkedNode();
        this->size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index > (size - 1))
            return -1;
        auto cur = dummyHead->next;
        while (index--)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val)
    {
        auto newNode = new LinkedNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        ++this->size;
    }

    void addAtTail(int val)
    {
        auto cur = this->dummyHead;
        while (cur->next != nullptr)
            cur = cur->next;
        auto newNode = new LinkedNode(val);
        cur->next = newNode;
        ++this->size;
    }

    void addAtIndex(int index, int val)
    {
        if (index > this->size)
            return;
        if (index < 0)
        {
            this->addAtHead(val);
            return;
        }
        if (index == this->size)
        {
            this->addAtTail(val);
            return;
        }

        auto cur = dummyHead;
        while(index--)
            cur = cur->next;
        auto newNode = new LinkedNode(val);
        newNode->next = cur->next;
        cur->next = newNode;
        ++this->size;
    }

    void deleteAtIndex(int index)
    {
        if (index >= this->size || index < 0)
            return;
        auto cur = dummyHead;
        while(index--)
            cur = cur->next;
        auto temp = cur->next; // index
        cur->next = temp->next;
        delete temp;
        temp = nullptr;
        --this->size;
    }

    int size = 0;
    LinkedNode *dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
