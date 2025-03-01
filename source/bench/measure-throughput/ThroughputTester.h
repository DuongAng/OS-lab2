//
// Created by duongang on 2/20/2025.
//

#ifndef THROUGHPUTTESTER_H
#define THROUGHPUTTESTER_H

#include <vector>
#include <cstddef>

class ThroughputTester {
public:
  ThroughputTester();

  static void measureSequentialWriteThroughput(size_t blockSize, size_t totalDataSize);

  static void printHelp();
};
#endif //THROUGHPUTTESTER_H
