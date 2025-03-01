//
// Created by duongang on 12/5/2024.
//

#include "FileFinder.h"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

FileFinder::FileFinder() {}

std::vector<std::string> FileFinder::findFileByName(const std::string& fileName, const std::string& directory) {
  std::vector<std::string> foundFiles;
  if (!fs::exists(directory) || !fs::is_directory(directory)) {
    std::cout << "Directory does not exist: " << directory << std::endl;
    return foundFiles; // Trả về danh sách rỗng nếu thư mục không tồn tại
  }

  searchDirectory(directory, fileName, foundFiles);
  return foundFiles;
}

void FileFinder::searchDirectory(const std::string& directory, const std::string& fileName, std::vector<std::string>& foundFiles) {
  for (const auto& entry : fs::directory_iterator(directory)) {
    if (entry.is_directory()) {
      // Nếu là thư mục, gọi đệ quy để tìm trong thư mục đó
      searchDirectory(entry.path().string(), fileName, foundFiles);
    } else if (entry.path().filename() == fileName) {
      // Nếu tên file trùng khớp, thêm vào danh sách
      foundFiles.push_back(entry.path().string());
    }
  }
}

void FileFinder::printHelp() {
  std::cout << "List subcommands: \n"
            << "\tsearch_name <file_name> <directory_path>\n\t\tFind files in the file system by name\n"
            << "\tfull-bench <file_name> <directory_path> <repeat-times>\n\t\tFind files in the file system by name.And repeat it several times.\n"
            << "\thelp\n\t\tPrints help message. \n";
}
