//
// Created by duongang on 2/20/2025.
//

#include <iostream>
#include "ThroughputTester.h"
#include <chrono>

int main(int argc, const char * argv[]) {
  if (argc < 2) {
    ThroughputTester::printHelp();
    return 1;
  }

  std::string command = argv[1];

  if (command == "thp_test") {
    if (argc < 4) {
      std::cout << "Usage: program thp_test <block_size(KB)> <total_data_sizes(MB)>" << std::endl;
      return 1;
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    size_t block_size = atoi(argv[2]);
    size_t total_data_sizes = atoi(argv[3]);
    ThroughputTester::measureSequentialWriteThroughput(block_size, total_data_sizes);
    std::cout << std::endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    std::cout << "Total execution time: "<< elapsed.count() << " seconds\n" << std::endl;
  } else if (command == "help") {
    ThroughputTester::printHelp();
  } else if (command == "full-bench") {
    if (argc < 5) {
      std::cout << "Usage: program thp_test <block_size(KB)> <total_data_sizes(MB)> <repeat_times>" << std::endl;
      return 1;
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    size_t block_size = atoi(argv[2]);
    size_t total_data_sizes = atoi(argv[3]);
    size_t repeat_times = atoi(argv[4]);
    for (int i = 0; i < repeat_times; i++) {
      ThroughputTester::measureSequentialWriteThroughput(block_size, total_data_sizes);
      std::cout << std::endl;
      std::cout << "------------------------------------------------------" << std::endl;
    }
    std::cout << std::endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    std::cout << "Total execution time: "<< elapsed.count() << " seconds\n" << std::endl;
  } else {
    std::cout << "Unknown command: " << command << std::endl;
    ThroughputTester::printHelp();
    return 1;
  }
  return 0;
}