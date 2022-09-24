#ifndef __0146_H
#define __0146_H

/****************************************************
Description:
Design and implement a data structure for Least Recently Used (LRU) cache. It
should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists
in the cache, otherwise return -1. put(key, value) - Set or insert the value if
the key is not already present. When the cache reached its capacity, it should
invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:
LRUCache cache = new LRUCache(2);
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
****************************************************/

#include "../includes.hpp"

class LRUCache {
public:
    unordered_map<int, int> cache_;
    unordered_map<int, int> visitCnt_;
    queue<int> visit_;
    int capacity_;
    int curUsage_;

    LRUCache(int capacity) {
        curUsage_ = 0;
        capacity_ = capacity;
    }

    void updateLeastRecentKey(int key) {
        auto it = visitCnt_.find(key);
        if (it == visitCnt_.end()) {
            visitCnt_[key] = 1;
        } else {
            visitCnt_[key] += 1;
        }
        visit_.push(key);
    }

    int findLeastRecentKey() {
        int key;
        while (true) {
            key = visit_.front();
            visit_.pop();
            if (visitCnt_[key] == 1) {
                auto it = visitCnt_.find(key);
                visitCnt_.erase(it);
                break;
            } else {
                visitCnt_[key] -= 1;
            }
        }
        return key;
    }

    int get(int key) {
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            // Update the least recent viewed
            updateLeastRecentKey(key);
            return it->second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            cache_[key] = value;
            updateLeastRecentKey(key);
            return;
        }
        if (curUsage_ < capacity_) {
            cache_[key] = value;
            updateLeastRecentKey(key);
            ++curUsage_;
            return;
        } else {
            // find the least recently viewed key
            int lrKey = findLeastRecentKey();
            auto it = cache_.find(lrKey);
            cache_.erase(it);
            cache_[key] = value;
            updateLeastRecentKey(key);
        }
    }

    void printMap(unordered_map<int, int> uom) {
        cout << "--------- suom ---------" << endl;
        for (auto c : uom)
            cout << c.first << " " << c.second << endl;
        cout << "--------- euom ---------" << endl;
    }

    void printQueue(queue<int> q) {
        cout << "--------- sque ---------" << endl;
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n--------- eque ---------" << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif
