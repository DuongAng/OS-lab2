#ifndef LAB2_H
#define LAB2_H

#include <windows.h>
#include <iostream>
#include <unistd.h>
#include <cstdint>
#include "cache.h"

typedef long long access_hint_t; // dự đoán thời gian truy cập

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

extern "C" {
    EXPORT intptr_t lab2_open(const char *path, bool use_cache);
    EXPORT int lab2_close(intptr_t fd);
    EXPORT ssize_t lab2_read(intptr_t fd, void *buf, size_t count, access_hint_t hint, bool use_cache);
    EXPORT ssize_t lab2_write(intptr_t fd, const void *buf, size_t count, access_hint_t hint);
    EXPORT off_t lab2_lseek(intptr_t fd, off_t offset, int whence);
    EXPORT int lab2_fsync(intptr_t fd);
    EXPORT int lab2_advice(intptr_t fd, off_t offset, access_hint_t hint);
}

#endif
