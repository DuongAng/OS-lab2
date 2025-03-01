//
// Created by duongang on 2/20/2025.
//

#include "ThroughputTester.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <filesystem>

using namespace std;

ThroughputTester::ThroughputTester() {}

namespace fs = std::filesystem;

void ThroughputTester::measureSequentialWriteThroughput(size_t blockSize, size_t totalDataSize) {
  blockSize = blockSize * 1024;
  totalDataSize = totalDataSize * 1024 * 1024;
  const string tempFileName = "temp_test_file.dat";
  // Calculate number of blocks
  size_t numBlocks = totalDataSize / blockSize;

  // Prepare data block
  vector<char> data(blockSize, 'a');  // Fill block with dummy data

  // Start measuring time
  auto startTime = chrono::high_resolution_clock::now();

  // Open file for writing
  ofstream outFile(tempFileName, ios::binary | ios::trunc);

  if (!outFile.is_open()) {
    cerr << "Failed to open file for writing.\n";
    return;
  }

  // Write data to file sequentially
  for (size_t i = 0; i < numBlocks; ++i) {
    outFile.write(data.data(), blockSize);
  }

  outFile.close();

  // End measuring time
  auto endTime = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = endTime - startTime;

  // Calculate throughput in MB/s
  double throughput = (totalDataSize / (1024.0 * 1024.0)) / elapsed.count();

  cout << "Block Size: " << blockSize << " bytes, Throughput: " << throughput << " MB/s\n";
  // Remove the temporary file
  fs::remove(tempFileName);
}

void ThroughputTester::printHelp() {
  std::cout << "List subcommands: \n"
            << "\tthp_test <block_size KB > <total_data_sizes MB >\n\t\tMeasuring the sequential write throughput of a drive with Block Size\n"
            << "\tfull-bench <block_size KB > <total_data_sizes MB > <repeat_times>\n\t\tMeasuring the sequential write throughput of a drive with Block Size\n"
            << "\thelp\n\t\tPrints help message. \n";
}

