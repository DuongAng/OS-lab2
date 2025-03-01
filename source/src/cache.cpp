#include "cache.h"

// trả về true nếu dữ liệu có trong cache
bool BlockCache::get(off_t offset, char *buf, size_t size) {
    if (cache.find(offset) != cache.end()) {
        memcpy(buf, cache[offset].data.data(), size);
        return true;
    }
    return false;
}

// Thêm dữ liệu vào trong cache nếu đầy theo chính sách optimal
void BlockCache::put(off_t offset, const char *data, size_t size, access_hint_t hint) {
    if (cache.size() >= MAX_CACHE_SIZE) {
        off_t victimOffset = findOptimalEviction();
        cache.erase(victimOffset);
    }
    cache[offset] = {offset, std::vector<char>(data, data + size), hint};
}

// Gợi ý truy cập trước
void BlockCache::set_advice(off_t offset, access_hint_t hint) {
    if (cache.find(offset) != cache.end()) {
        cache[offset].hint = hint;
    }
}

// tìm phần tử có hint lớn nhất để thay
off_t BlockCache::findOptimalEviction() {
    off_t victim = -1;
    access_hint_t farthest = -1;

    for (const auto& entry : cache) {
        if (entry.second.hint > farthest) {
            farthest = entry.second.hint;
            victim = entry.first;
        }
    }
    return victim;
}
