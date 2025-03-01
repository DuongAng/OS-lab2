#include "lab2.h"
#include <cstdint>

BlockCache cacheManager;

EXPORT intptr_t lab2_open(const char *path, bool use_cache) {
    DWORD flags = FILE_ATTRIBUTE_NORMAL;
    if (!use_cache) {
        flags |= FILE_FLAG_NO_BUFFERING | FILE_FLAG_WRITE_THROUGH;
    }

    HANDLE hFile = CreateFileA(path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, flags, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "[ERROR] Failed to open file: " << path << std::endl;
        return -1;
    }

    return reinterpret_cast<intptr_t>(hFile);
}

EXPORT int lab2_close(intptr_t fd) {
    return CloseHandle(reinterpret_cast<HANDLE>(fd)) ? 0 : -1;
}

EXPORT ssize_t lab2_read(intptr_t fd, void *buf, size_t count, access_hint_t hint, bool use_cache) {
    off_t offset = lab2_lseek(fd, 0, SEEK_CUR);

    if (use_cache && cacheManager.get(offset, (char*)buf, count)) {
        return count;
    }

    DWORD bytesRead;
    BOOL success = ReadFile(reinterpret_cast<HANDLE>(fd), buf, (DWORD)count, &bytesRead, NULL);
    if (!success) return -1;

    if (use_cache) {
        cacheManager.put(offset, (char*)buf, count, hint);
    }

    return bytesRead;
}

EXPORT ssize_t lab2_write(intptr_t fd, const void *buf, size_t count, access_hint_t hint) {
    off_t offset = lab2_lseek(fd, 0, SEEK_CUR);

    // ✅ Ghi dữ liệu xuống file thực sự
    DWORD bytesWritten;
    BOOL success = WriteFile(reinterpret_cast<HANDLE>(fd), buf, (DWORD)count, &bytesWritten, NULL);
    if (!success || bytesWritten != count) {
        std::cerr << "[ERROR] Failed to write to file!" << std::endl;
        return -1;  // Trả về lỗi nếu không ghi đủ bytes
    }

    std::cout << "[SUCCESS] Data written to file at offset " << offset << std::endl;

    // ✅ Ghi vào cache để có lợi cho performance
    cacheManager.put(offset, (const char *)buf, count, hint);

    // ✅ Gọi fsync() để đảm bảo dữ liệu có trên đĩa
    int sync_result = lab2_fsync(fd);
    if (sync_result != 0) {
        std::cerr << "[ERROR] Failed to sync file!" << std::endl;
        return -1;
    }

    std::cout << "[SUCCESS] Data synchronized to disk." << std::endl;
    return count;
}



EXPORT off_t lab2_lseek(intptr_t fd, off_t offset, int whence) {
    return SetFilePointer(reinterpret_cast<HANDLE>(fd), offset, NULL, whence);
}

EXPORT int lab2_fsync(intptr_t fd) {
    if (fd <= 0) {
        std::cerr << "[ERROR] Invalid file descriptor in fsync!" << std::endl;
        return -1;
    }

    BOOL result = FlushFileBuffers(reinterpret_cast<HANDLE>(fd));
    if (!result) {
        DWORD errorCode = GetLastError();
        std::cerr << "[ERROR] FlushFileBuffers failed with error code: " << errorCode << std::endl;
        return -1;
    }

    std::cout << "[SUCCESS] File synchronized to disk." << std::endl;
    return 0;
}



EXPORT int lab2_advice(intptr_t fd, off_t offset, access_hint_t hint) {
    cacheManager.set_advice(offset, hint);
    return 0;
}
