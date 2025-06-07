/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <unordered_map>
#include <list>
#include <iterator>

// 1.首先需要个hash map存所有键值对
// 2.需要存key的使用顺序,用什么啊？——双向链表
// @lc code=start
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->cap = capacity;
    }

    int get(int key)
    {
        auto it = values.find(key);
        if (it == values.end())
            return -1;
        // 移动节点到头部
        auto it1 = map.find(key);
        key_order.splice(key_order.begin(), key_order, it1->second);
        return it->second;
    }

    void put(int key, int value)
    {
        auto it = this->map.find(key);
        // key存在
        if (it != this->map.end())
        {
            values[key] = value;
            key_order.splice(key_order.begin(), key_order, it->second);
        }
        // key不存在
        else
        {
            // 满了
            if (this->key_order.size() >= cap)
            {
                // 找到LRU的key并删掉
                auto remove_key = key_order.back();
                values.erase(remove_key);
                map.erase(remove_key);
                key_order.pop_back();
            }

            // 添加新key
            key_order.push_front(key);
            values[key] = value;
            map.emplace(key, key_order.begin());
        }
    }

private:
    std::unordered_map<int, std::list<int>::iterator> map; // key和key_order迭代器的映射
    std::unordered_map<int, int> values;                   // key和value的映射
    std::list<int> key_order;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
