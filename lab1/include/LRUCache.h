#ifndef LAB1_LRUCACHE_H
#define LAB1_LRUCACHE_H

#include "ICache.h"
#include<unordered_map>
#include<list>

class LRUCache : public ICache {
private:
    std::size_t capacity;
    std::list<std::pair<int, long long>> cache;
    std::unordered_map<int, std::list<std::pair<int, long long>>::iterator> cache_map;
public:
    LRUCache(const std::size_t capacity);
    void put(int key, long long value) override;
    long long get(int key) override;
    long long operator[](int key) override;
};
#endif