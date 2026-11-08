#include <gtest/gtest.h>
#include "../include/LRUCache.h"
#include <stdexcept>

TEST(LRUCacheTest, Constructor) {
    LRUCache cache(5);

    cache.put(1, 100);

    EXPECT_EQ(cache.get(1), 100);
}

TEST(LRUCacheTest, ZeroCapacity) {
    EXPECT_THROW(LRUCache cache(0), std::invalid_argument);
}

TEST(LRUCacheTest, Put) {
    LRUCache cache(3);

    cache.put(1, 100);

    EXPECT_EQ(cache.get(1), 100);
}

TEST(LRUCacheTest, PutSeveral) {
    LRUCache cache(3);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    EXPECT_EQ(cache.get(1), 100);
    EXPECT_EQ(cache.get(2), 200);
    EXPECT_EQ(cache.get(3), 300);
}

TEST(LRUCacheTest, Get) {
    LRUCache cache(3);

    cache.put(1, 100);

    EXPECT_EQ(cache.get(1), 100);
}

TEST(LRUCacheTest, GetException) {
    LRUCache cache(3);

    EXPECT_THROW(cache.get(42), std::out_of_range);
}

TEST(LRUCacheTest, UpdateValue) {
    LRUCache cache(3);

    cache.put(1, 100);
    cache.put(1, 500);

    EXPECT_EQ(cache.get(1), 500);
}

TEST(LRUCacheTest, Eviction) {
    LRUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    EXPECT_THROW(cache.get(1), std::out_of_range);
    EXPECT_EQ(cache.get(2), 200);
    EXPECT_EQ(cache.get(3), 300);
}

TEST(LRUCacheTest, GetChangesOrder) {
    LRUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);

    cache.get(1);
    cache.put(3, 300);

    EXPECT_THROW(cache.get(2), std::out_of_range);
    EXPECT_EQ(cache.get(1), 100);
    EXPECT_EQ(cache.get(3), 300);
}

TEST(LRUCacheTest, UpdateChangesOrder) {
    LRUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);

    cache.put(1, 500);
    cache.put(3, 300);

    EXPECT_THROW(cache.get(2), std::out_of_range);
    EXPECT_EQ(cache.get(1), 500);
    EXPECT_EQ(cache.get(3), 300);
}

TEST(LRUCacheTest, MultipleEvictions) {
    LRUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    EXPECT_THROW(cache.get(1), std::out_of_range);

    cache.put(4, 400);

    EXPECT_THROW(cache.get(2), std::out_of_range);
    EXPECT_EQ(cache.get(3), 300);
    EXPECT_EQ(cache.get(4), 400);
}

TEST(LRUCacheTest, Operator) {
    LRUCache cache(3);

    cache.put(1, 100);

    EXPECT_EQ(cache[1], 100);
}

TEST(LRUCacheTest, OperatorException) {
    LRUCache cache(3);

    EXPECT_THROW(cache[42], std::out_of_range);
}

