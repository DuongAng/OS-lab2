#include "lab2.h"
#include <iostream>
#include <vector>
#include <ctime>

void test_performance(const char *filename, bool use_cache) {
    intptr_t fd = lab2_open(filename, use_cache);
    if (fd < 0) return;

    std::vector<char> buffer(4096);

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        access_hint_t hint = i * 10;
        lab2_advice(fd, i * 4096, hint);
        lab2_read(fd, buffer.data(), buffer.size(), hint, use_cache);
    }
    clock_t end = clock();

    std::cout << "[RESULT] Time taken " << (use_cache ? "WITH" : "WITHOUT") << " Cache: "
              << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    lab2_close(fd);
}

int main() {
    test_performance("testfile_large.txt", true);
    test_performance("testfile_large.txt", false);
    return 0;
}
