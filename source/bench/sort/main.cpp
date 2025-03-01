//
// Created by duongang on 2/20/2025.
//

#include <iostream>
#include "Sort.h"
#include <chrono>

int main(int argc, const char * argv[]) {
  if (argc < 2) {
    Sorter::printHelp();
    return 1;
  }

  std::string command = argv[1];

  if (command == "sort") {
    if (argc != 5) {
      std::cout << "Usage: program sort <size> <min_value> <max_value>" << std::endl;
      return 1;
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    int size = atoi(argv[2]);
    int min_value = atoi(argv[3]);
    int max_value = atoi(argv[4]);
    std::vector<int> random_array = Sorter::CreateArray(size, min_value, max_value);
    std::cout << "Random array: ";
    for (int num : random_array) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
    std::vector<int> sortedArray = Sorter::Sort(random_array);
    std::cout << "Sorted array: ";
    for (int num : sortedArray) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    std::cout << "Total execution time: "<< elapsed.count() << " seconds\n" << std::endl;
  } else if (command == "help") {
    Sorter::printHelp();
  } else if (command == "full-bench") {
    if (argc != 6) {
      std::cout << "Usage: program full-bench <size> <min_value> <max_value> <repeat_times>" << std::endl;
      return 1;
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    int size = atoi(argv[2]);
    int min_value = atoi(argv[3]);
    int max_value = atoi(argv[4]);
    int repeat_times = atoi(argv[5]);

    for (int i = 0; i < repeat_times; i++) {
      std::vector<int> random_array = Sorter::CreateArray(size, min_value, max_value);
      std::cout << "Random array: ";
      for (int num : random_array) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
      std::vector<int> sortedArray = Sorter::Sort(random_array);
      std::cout << "Sorted array: ";
      for (int num : sortedArray) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
      std::cout << "------------------------------------------------------" << std::endl;
    }
    std::cout << std::endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    std::cout << "Total execution time: "<< elapsed.count() << " seconds\n" << std::endl;
  } else {
    std::cout << "Unknown command: " << command << std::endl;
    Sorter::printHelp();
    return 1;
  }

  return 0;
}