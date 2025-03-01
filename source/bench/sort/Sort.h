//
// Created by duongang on 2/20/2025.
//

#ifndef SORT_H
#define SORT_H
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>

class Sorter {
public:

  Sorter();

  static void BubbleSort(std::vector<int> &arr);

  static std::vector<int> CreateArray(int array_size, int minValue, int maxValue);

  static std::vector<int> Sort(std::vector<int>& array);

  static void printHelp();
};
#endif //SORT_H
