#include "../include/LRUCache.h"

#include <stdexcept>

LRUCache::LRUCache(std::size_t capacity) : capacity(capacity) {
    if (capacity == 0) {
        throw std::invalid_argument("Capacity must be greater than 0");
    }
}

void LRUCache::put(int key, long long value) {
    auto it = cache_map.find(key);
    if (it != cache_map.end()) {
        it->second->second = value;
        cache.splice(cache.begin(), cache, it->second);
        return;
    }

    if (cache.size() == capacity) {
        cache_map.erase(cache.back().first);
        cache.pop_back();
    }
    cache.emplace_front(key, value);
    cache_map[key] = cache.begin();
}

long long LRUCache::get(int key) {
    auto it = cache_map.find(key);
    if (it == cache_map.end()) {
        throw std::out_of_range("Key not found");
    }
    cache.splice(cache.begin(), cache, it->second);
    return it->second->second;
}

long long LRUCache::operator[](int key) {
    return get(key);
}
