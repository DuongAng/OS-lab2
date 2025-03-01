//
// Created by duongang on 12/5/2024.
//

#include "ArrayDedup.h"

#include <iostream>

ArrayDedup::ArrayDedup() {}


// Hàm tạo mảng ngẫu nhiên
std::vector<int> ArrayDedup::generateRandomArray(size_t size, int minValue, int maxValue) {
  std::vector<int> array(size);
  std::random_device rd; // Sử dụng để tạo số ngẫu nhiên
  std::mt19937 gen(rd()); // Khởi tạo bộ sinh số ngẫu nhiên
  std::uniform_int_distribution<> dis(minValue, maxValue); // Phân phối số nguyên

  for (size_t i = 0; i < size; ++i) {
    array[i] = dis(gen); // Gán giá trị ngẫu nhiên cho từng phần tử
  }
  return array;
}

// Hàm loại bỏ các phần tử trùng lặp trong mảng
std::vector<int> ArrayDedup::deduplicate(const std::vector<int>& array) {
  std::vector<int> uniqueArray = array; // Sao chép mảng ban đầu
  std::sort(uniqueArray.begin(), uniqueArray.end()); // Sắp xếp mảng
  auto last = std::unique(uniqueArray.begin(), uniqueArray.end()); // Xóa các phần tử trùng lặp
  uniqueArray.erase(last, uniqueArray.end()); // Cắt bỏ các phần tử còn lại
  return uniqueArray;
}

void ArrayDedup::printHelp() {
   std::cout << "List subcommands: \n"
             << "\tdedup <size> <min_value> <max_value>\n\t\tGenerate a random array and deduplicate it.\n"
             << "\tfull-bench <size> <min_value> <max_value> <repeat-times>\n\t\tGenerate a radom array and deduplicate it. Then repeat everething several times.\n"
             << "\thelp\n\t\tPrints help message.\n";
 }