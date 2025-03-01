//
// Created by duongang on 12/5/2024.
//

#ifndef ARRAY_DEDUP_H
#define ARRAY_DEDUP_H

#include <vector>
#include <random>
#include <algorithm>

class ArrayDedup {
public:

  ArrayDedup();
  // Phương thức tạo mảng ngẫu nhiên
  static std::vector<int> generateRandomArray(size_t size, int minValue, int maxValue);

  // Phương thức loại bỏ các phần tử trùng lặp trong mảng
  static std::vector<int> deduplicate(const std::vector<int>& array);

  static void printHelp();
};
#endif //ARRAY_DEDUP_H
