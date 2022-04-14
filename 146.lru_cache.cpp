/**
 * @file 146.lru_cache.cpp
 * @author your name (you@domain.com)
 * @brief LRU最近最久未使用算法
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <unordered_map>
using namespace std;

// 双向链表的节点定义
struct DeListNode
{
    int key;
    int value;
    DeListNode* pre;
    DeListNode* next;
    DeListNode(): key(0), value(0), pre(nullptr), next(nullptr) {}
    DeListNode(int k, int v): key(k), value(v), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        dummy_head = new DeListNode();
        dummy_tail = new DeListNode();
        dummy_head->next = dummy_tail;
        dummy_tail->pre = dummy_head;
    }
    
    int get(int key) {
        if(dic.count(key) != 0)
        {
            auto node = dic[key];
            removeNode(node);
            addHeadNode(node);
            return dic[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(dic.count(key) != 0)   // 缓存中存在
        {
            dic[key]->value = value;
            //moveToHead(dic[key]);
            removeNode(dic[key]);
            addHeadNode(dic[key]);
        }
        else    // 缓存中不存在，需要插入
        {
            DeListNode* node = new DeListNode(key, value);
            addHeadNode(node);
            dic[key] = node;
            ++size;
            if(size > capacity)   // 缓存超出容量
            {
                dic.erase(dummy_tail->pre->key);
                removeNode(dummy_tail->pre);
                --size;
            }
        }
    }

    // 删除链表中的指定节点
    void removeNode(DeListNode* node)
    {
        node->next->pre = node->pre;
        node->pre->next = node->next;
        delete node;
    }

    // 向链表头部添加节点
    void addHeadNode(DeListNode* node)
    {
        node->next = dummy_head->next;
        dummy_head->next->pre = node;
        node->pre = dummy_head;
        dummy_head->next = node;
    }

private:
    int size = 0;    // 当前的缓存大小
    int capacity = 0;   // 总的缓存大小
    unordered_map<int, DeListNode*> dic;
    DeListNode* dummy_head = nullptr;
    DeListNode* dummy_tail = nullptr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    int p1 = obj->get(1);
    obj->put(3, 3);
    int p2 = obj->get(2);
    obj->put(4, 4);
    int p3 = obj->get(1);
    int p4 = obj->get(3);
    int p5 = obj->get(4);
    delete obj;
    return 0;
}