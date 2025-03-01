//
// Created by duongang on 12/5/2024.
//

#include <iostream>
#include "FileFinder.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    FileFinder::printHelp();
    return 1;
  }

  std::string command = argv[1];

  if (command == "search_name") {
    if (argc != 4) {
      std::cout << "Usage: program search_name <file_name> <directory_path>" << std::endl;
      return 1;
    }

    std::string file_name = argv[2];
    std::string directory_path = argv[3];
    std::vector<std::string> results = FileFinder::findFileByName(file_name,directory_path);
    if (results.empty()) {
      std::cout << "Can't find file '" << file_name << "' in directory '" << directory_path << "'.\n";
    } else {
      std::cout << "Found files:\n";
      for (const auto& path : results) {
        std::cout << path << std::endl;
      }
    }
  } else if (command == "help") {
    FileFinder::printHelp();
  } else if (command == "full-bench") {
    if (argc != 5) {
      std::cout << "Usage: program search_name <file_name> <directory_path> <repeat-times>" << std::endl;
      return 1;
    }
    std::string file_name = argv[2];
    std::string directory_path = argv[3];
    int repeat_times = atoi(argv[4]);

    for (int i = 0; i < repeat_times; i++) {
      std::vector<std::string> results = FileFinder::findFileByName(file_name,directory_path);
      if (results.empty()) {
        std::cout << "Can't find file '" << file_name << "' in directory '" << directory_path << "'.\n";
      } else {
        std::cout << "Found files:\n";
        for (const auto& path : results) {
          std::cout << path << std::endl;
        }
      }
    }

  }else {
    std::cout << "Unknown command: " << command << std::endl;
    FileFinder::printHelp();
    return 1;
  }

  return 0;
}
