#include "../include/LFUCache.h"

#include <algorithm>
#include <stdexcept>

LFUCache::LFUCache(std::size_t capacity) : capacity(capacity) {
   if (capacity == 0) {
      throw std::invalid_argument("Capacity must be greater than 0");
   }
}

void LFUCache::put(int key, long long value) {
   auto it = values.find(key);
   if (it != values.end()) {
      it->second = value;

      ++frequencies[key];
      last_used[key] = ++access_counter;

      return;
   }

   if (values.size() == capacity) {
      auto min_key = std::min_element(frequencies.begin(), frequencies.end(), [this](const auto& a, const auto& b) {
         if (a.second != b.second) {
            return a.second < b.second;
        }
        return last_used[a.first] < last_used[b.first];
      })->first;
      values.erase(min_key);
      frequencies.erase(min_key);
      last_used.erase(min_key);
   }

   values[key] = value;
   frequencies[key] = 1;
   last_used[key] = ++access_counter;


}

long long LFUCache::get(int key) {
   auto it = values.find(key);
   if (it == values.end()) {
      throw std::out_of_range("Key not found");
   }
   ++frequencies[key];
   last_used[key] = ++access_counter;
   return it->second;

}

long long LFUCache::operator[](int key) {
   return get(key);
}
