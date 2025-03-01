#include "lab2.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

void test_full_cycle() {
    std::cout << "[TEST] Running full API test cycle\n";

    // Bước 1: Mở file
    intptr_t fd = lab2_open("testfile.txt", true);
    assert(fd >= 0);
    std::cout << "[SUCCESS] File opened successfully\n";

    // Bước 2: Viết dữ liệu vào file
    const char *writeData = "Hello, Lab2!";
    ssize_t bytesWritten = lab2_write(fd, writeData, strlen(writeData), 0);
    assert(bytesWritten == strlen(writeData));
    std::cout << "[SUCCESS] Data written successfully\n";

    // Bước 3: Đồng bộ dữ liệu xuống đĩa
    int syncResult = lab2_fsync(fd);
    assert(syncResult == 0);
    std::cout << "[SUCCESS] Data synchronized to disk\n";

    // Bước 4: Đóng file
    lab2_close(fd);
    std::cout << "[SUCCESS] File closed after writing\n";

    // Bước 5: Mở lại file để kiểm tra nội dung
    fd = lab2_open("testfile.txt", true);
    assert(fd >= 0);
    std::cout << "[SUCCESS] File reopened for reading\n";

    // Bước 6: Đọc dữ liệu từ file
    char readBuffer[20] = {0};
    ssize_t bytesRead = lab2_read(fd, readBuffer, strlen(writeData), 0, true);
    assert(bytesRead == strlen(writeData));
    std::cout << "[SUCCESS] Data read successfully: " << readBuffer << "\n";

    // Bước 7: Kiểm tra nội dung file có khớp với dữ liệu đã ghi không
    assert(strcmp(writeData, readBuffer) == 0);
    std::cout << "[SUCCESS] File content matches expected output\n";

    // Bước 8: Đóng file sau khi kiểm tra
    lab2_close(fd);
    std::cout << "[SUCCESS] File closed after reading\n";

    std::cout << "[TEST COMPLETED SUCCESSFULLY]\n";
}

void test_lseek() {
    std::cout << "[TEST] Testing lab2_lseek()" << std::endl;
    intptr_t fd = lab2_open("testfile.txt", true);
    assert(fd >= 0);

    lab2_write(fd, "1234567890", 10, 0);  // Ghi 10 ký tự
    lab2_lseek(fd, 5, SEEK_SET);  // Di chuyển con trỏ đến vị trí 5
    lab2_write(fd, "HELLO", 5, 0);  // Ghi "HELLO" tại vị trí 5

    lab2_fsync(fd);  // Đồng bộ dữ liệu xuống đĩa
    lab2_close(fd);

    // Kiểm tra dữ liệu đã được ghi đúng
    std::ifstream file("testfile.txt");
    std::string content;
    file >> content;
    file.close();
    assert(content == "12345HELLO2!");  // Kiểm tra kết quả mong đợi
    std::cout << "[SUCCESS] lseek() worked correctly, file content: " << content << std::endl;
}


int main() {
    test_full_cycle();
    test_lseek();
    return 0;
}
