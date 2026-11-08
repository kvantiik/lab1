#include "../include/CacheWrapper.h"

#include <stdexcept>

CacheWrapper::CacheWrapper(ICache &cache):cache(cache) {}

long long CacheWrapper::Fibonacci(int n) {
    try {
        return cache.get(n);
    }
    catch (const std::out_of_range& e) {
        long long result = 0;
        if (n<0) {
            throw std::invalid_argument("n must be greater than or equal to 0");
        }
        if (n == 0) {
            result = 0;
        }
        else if (n == 1) {
            result = 1;
        }
        else {
            result = Fibonacci(n - 1) + Fibonacci(n - 2);
        }
        cache.put(n, result);
        return result;
    }
}
