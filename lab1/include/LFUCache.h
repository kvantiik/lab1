#ifndef LAB1_LFUCACHE_H
#define LAB1_LFUCACHE_H

#include "ICache.h"
#include <unordered_map>

class LFUCache : public ICache {
private:
    std::size_t capacity;
    std::size_t access_counter = 0;

    std::unordered_map<int, long long> values;
    std::unordered_map<int, std::size_t> frequencies;
    std::unordered_map<int, std::size_t> last_used;

public:
    LFUCache(std::size_t capacity);

    void put(int key, long long value) override;
    long long get(int key) override;
    long long operator[](int key) override;
};

#endif