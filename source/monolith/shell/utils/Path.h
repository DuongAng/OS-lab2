//
// Created by duongang on 12/6/2024.
//

#ifndef PATH_H
#define PATH_H

#include <string>
#include <vector>

std::pair<std::string, int> pwd();
std::pair<std::string, int> cd(const std::string& path);
std::pair<std::vector<std::string>, int> ls();
std::pair<std::vector<std::string>, int> ls(const std::string& path);

#endif //PATH_H
