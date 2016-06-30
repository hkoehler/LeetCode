// https://leetcode.com/problems/lru-cache/

#include <unordered_map>
#include <iostream>
#include <cassert>

using namespace std;

class LRUCache{
    struct Item {
      Item(int k, int v) : key(k), value(v) {
        prev = next = this;
      }
      int key, value;
      Item *prev, *next;
    };
    
    unordered_map<int, Item*> cache;
    Item lru;
    int maxSize, currSize;
public:
    LRUCache(int capacity) : lru(-1, -1) {
        maxSize = capacity;
        currSize = 0;
    }
    
    // insert item at front
    void insert(Item *item) {
        Item *tmp = lru.next;
        
        lru.next = item;
        item->prev = &lru;
        item->next = tmp;
        tmp->prev = item;
    }
    
    // remove item
    void remove(Item *item) {
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }
    
    int get(int key) {
        auto i = cache.find(key);
        if (i != cache.end()) {
            Item *item = i->second;
            remove(item);
            insert(item);
            return item->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto i = cache.find(key);
        
        if (maxSize == 0)
            return;
        if (i != cache.end()) {
            Item *item = i->second;
            remove(item);
            insert(item);
            item->value = value;
        } else {
            if (currSize == maxSize) {
                // remove at rear
                Item *item = lru.prev;
                //cout << "remove " << item->key << " at rear" << endl;
                remove(item);
                cache.erase(item->key);
                delete item;
                currSize--;
            }
            Item *newItem = new Item(key, value);
            insert(newItem);
            cache.insert(make_pair(key, newItem));
            currSize++;
        }
    }
};

void test1()
{
    int rc;
    LRUCache c(5);
    
    rc = c.get(1);
    assert(rc == -1);
    c.set(1, 1);
    rc = c.get(1);
    assert(rc == 1);
    c.set(2,2);
    c.set(3,3);
    c.set(4,4);
    c.set(5,5);
    c.set(6,6); // (1,1) pushed out
    rc = c.get(1);
    assert(rc == -1);
    rc = c.get(2); // move (2,2) to head
    assert(rc == 2);
    c.set(7,7); // (3,3) pushed out
    rc = c.get(3);
    assert(rc == -1);
}

void test2()
{
    int rc;
    LRUCache c(0);
    
    rc = c.get(1);
    assert(rc == -1);
    c.set(1, 1);
    rc = c.get(1);
    assert(rc == -1);
}

void test3()
{
    int rc;
    LRUCache c(1);
    
    rc = c.get(1);
    assert(rc == -1);
    c.set(1, 1);
    rc = c.get(1);
    assert(rc == 1);    
    c.set(2, 2);
    rc = c.get(1);
    assert(rc == -1);    

    rc = c.get(2);
    assert(rc == 2);
    c.set(2, 22);
    rc = c.get(2);
    assert(rc == 22);
}

void test4()
{
    int rc;
    LRUCache c(10);
    
    for (int i = 1; i <= 20; i++)
        c.set(i, i);
    for (int i = 1; i <= 10; i++) {
        rc = c.get(i);
        assert(rc == -1);
    }
}

int main(int argc, char *argv[])
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}

