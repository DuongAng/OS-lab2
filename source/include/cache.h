#ifndef CACHE_H
#define CACHE_H

#include <unordered_map>
#include <vector>
#include <iostream>
#include <cstring>

#define MAX_CACHE_SIZE 10 // giới hạn số trang trong cache

typedef long long access_hint_t; // dự đoán thời gian truy cập

struct CacheBlock {
    off_t offset;
    std::vector<char> data;
    access_hint_t hint;
};

class BlockCache {
private:
    std::unordered_map<off_t, CacheBlock> cache;

public:
    BlockCache() = default;

    bool get(off_t offset, char *buf, size_t size);
    void put(off_t offset, const char *data, size_t size, access_hint_t hint);
    void set_advice(off_t offset, access_hint_t hint);
    off_t findOptimalEviction();
};

#endif
