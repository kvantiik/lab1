#include <gtest/gtest.h>
#include "../include/LFUCache.h"
#include <stdexcept>


TEST(LFUCacheTest, Constructor) {
    LFUCache cache(5);

    cache.put(1, 100);
    EXPECT_EQ(100, cache.get(1));
}


TEST(LFUCacheTest, ZeroCapacity) {
    EXPECT_THROW(LFUCache cache(0), std::invalid_argument);
}


TEST(LFUCacheTest, Put) {
    LFUCache cache(3);

    cache.put(1, 100);
    EXPECT_EQ(100, cache.get(1));
}


TEST(LFUCacheTest, PutSeveral) {
    LFUCache cache(3);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    EXPECT_EQ(100, cache.get(1));
    EXPECT_EQ(200, cache.get(2));
    EXPECT_EQ(300, cache.get(3));
}


TEST(LFUCacheTest, Get) {
    LFUCache cache(3);

    cache.put(1, 100);
    EXPECT_EQ(100, cache.get(1));
}


TEST(LFUCacheTest, GetException) {
    LFUCache cache(3);

    EXPECT_THROW(cache.get(69), std::out_of_range);
}


TEST(LFUCacheTest, PutUpdateValue) {
    LFUCache cache(3);

    cache.put(1, 100);
    cache.put(1, 500);

    EXPECT_EQ(500, cache.get(1));
}


TEST(LFUCacheTest, PutIncreasesFrequency) {
    LFUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);

    cache.put(1, 500);
    cache.put(3, 300);

    EXPECT_EQ(500, cache.get(1));
    EXPECT_EQ(300, cache.get(3));
    EXPECT_THROW(cache.get(2), std::out_of_range);
}


TEST(LFUCacheTest, GetIncreasesFrequency) {
    LFUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);

    cache.get(1);
    cache.put(3, 300);

    EXPECT_EQ(100, cache.get(1));
    EXPECT_EQ(300, cache.get(3));
    EXPECT_THROW(cache.get(2), std::out_of_range);
}


TEST(LFUCacheTest, Eviction) {
    LFUCache cache(3);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    cache.get(1);
    cache.get(1);
    cache.get(2);

    cache.put(4, 400);

    EXPECT_THROW(cache.get(3), std::out_of_range);

    EXPECT_EQ(100, cache.get(1));
    EXPECT_EQ(200, cache.get(2));
    EXPECT_EQ(400, cache.get(4));
}


TEST(LFUCacheTest, EvictionByLastUsed) {
    LFUCache cache(3);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    cache.get(1);
    cache.get(2);
    cache.get(3);

    cache.put(4, 400);

    EXPECT_THROW(cache.get(1), std::out_of_range);

    EXPECT_EQ(200, cache.get(2));
    EXPECT_EQ(300, cache.get(3));
    EXPECT_EQ(400, cache.get(4));
}


TEST(LFUCacheTest, MultipleEvictions) {
    LFUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    EXPECT_THROW(cache.get(1), std::out_of_range);

    cache.put(4, 400);

    EXPECT_THROW(cache.get(2), std::out_of_range);
    EXPECT_EQ(300, cache.get(3));
    EXPECT_EQ(400, cache.get(4));
}


TEST(LFUCacheTest, Operator) {
    LFUCache cache(3);

    cache.put(1, 100);

    EXPECT_EQ(100, cache[1]);
}


TEST(LFUCacheTest, OperatorException) {
    LFUCache cache(3);

    EXPECT_THROW(cache[42], std::out_of_range);
}


TEST(LFUCacheTest, OperatorIncreasesFrequency) {
    LFUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);

    cache[1];
    cache.put(3, 300);

    EXPECT_EQ(100, cache.get(1));
    EXPECT_EQ(300, cache.get(3));
    EXPECT_THROW(cache.get(2), std::out_of_range);
}