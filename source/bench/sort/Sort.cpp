//
// Created by duongang on 2/20/2025.
//

#include "./Sort.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

 Sorter::Sorter() {}


void Sorter::BubbleSort(std::vector<int> &arr) {
  int const size = arr.size();
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

std::vector<int> Sorter::CreateArray(int array_size, int minValue, int maxValue) {
   vector<int> arr(array_size);
   random_device random_device;
   mt19937 gen(random_device());
   uniform_int_distribution<> distrib(minValue, maxValue);
   for (int i = 0; i < array_size; ++i) {
     arr[i] = distrib(gen);
   }
   return arr;
 }

std::vector<int> Sorter::Sort(std::vector<int>& array) {
  // auto start_time = chrono::high_resolution_clock::now();
   BubbleSort(array);
  // auto end_time = chrono::high_resolution_clock::now();
  // chrono::duration<double> elapsed = end_time - start_time;
  // cout << "Total execution time: " << elapsed.count() << " seconds\n";
   return  array;
}

void Sorter::printHelp() {
  std::cout << "List subcommands: \n"
            <<"\tsort  <size> <min> <max>\n\t\tGenerate a random array and sort it in RAM.\n"
            <<"\tfull-bench <size> <min> <max> <repeat-time>\n\t\tGenerate a random array and sort it in RAM. Then repeat everything several times.\n"
            <<"\thelp\n\t\tPrints help message.\n";
}


