#ifndef LAB1_CACHEWRAPPER_H
#define LAB1_CACHEWRAPPER_H
#include "ICache.h"

class CacheWrapper {
private:
    ICache& cache;

public:
    CacheWrapper(ICache& cache);
    long long Fibonacci(int n);
};

#endif