#include <iostream>
#include "../include/LRUCache.h"
#include "../include/LFUCache.h"
#include "../include/CacheWrapper.h"

#include <gtest/gtest.h>

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void run(CacheWrapper &wrapper) {
    int n;

    while (true) {
        std::cout << "Enter n (-1 to exit): ";
        std::cin >> n;

        if (n == -1) {
            break;
        }

        std::cout << "Fibonacci: " << wrapper.Fibonacci(n) << '\n';
    }
}

