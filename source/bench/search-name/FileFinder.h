//
// Created by duongang on 12/5/2024.
//

#ifndef FILEFINDER_H
#define FILEFINDER_H

#include <string>
#include <vector>

class FileFinder {
public:
  // Constructor
  FileFinder();

  // Phương thức để tìm kiếm file theo tên
  static std::vector<std::string> findFileByName(const std::string& fileName, const std::string& directory);

  static void printHelp();

private:
  // Phương thức phụ để duyệt thư mục
  static void searchDirectory(const std::string& directory, const std::string& fileName, std::vector<std::string>& foundFiles);
};

#endif //FILEFINDER_H
